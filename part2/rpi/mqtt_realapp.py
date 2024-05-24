# mqtt_realapp.py
# 온습도 센서 데이터 통신, RGB LED

import paho.mqtt.client as mqtt
import RPi.GPIO as GPIO
import adafruit_dht
import board
import time
import datetime as dt # 언제 데이터를 만들었는지 확인하기 위함
import json # 데이터를 json화 시켜야 한다.


# RGB LED 설정
red_pin = 4
green_pin = 6
dht_pin = 18

dev_id = 'PKNU52'
loop_num = 0

# 초기화 시작

def onConnect(client, userdata, flags, reason_code, properties):
    print(f'연결 성공 : {reason_code}')
    client.subscribe('pknu/rcv')

def onMessage(client, userdata, msg):
    print(f'{msg.topic} + {msg.payload}')

GPIO.cleanup()
GPIO.setmode(GPIO.BCM)
GPIO.setup(red_pin, GPIO.OUT)
GPIO.setup(green_pin, GPIO.OUT) # LED 켜는 것 : 그래서 OUT
GPIO.setup(dht_pin, GPIO.IN) # 온습도 값을 RPi에서 받는 것 : 그래서 IN이다.
dhtDevice = adafruit_dht.DHT11(board.D18) # 중요

# 초기화 끝

# 실행 시작
mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2) # 2023.09 이후 버전업
mqttc.on_connect = onConnect # 접속시 이벤트
mqttc.on_message = onMessage # 메시지 출력

# 192.168.5.3 자신의 ip 입력
mqttc.connect('192.168.5.2', 1883, 60) # 60초 안에 실행안되면 종료하겠다.

mqttc.loop_start() # 영원히 돌린다.
while True:
    time.sleep(2) # 1초마다 데이터를 갱신할 경우 잘 못받아오는 일이 생기는걸 확인 -> 2초마다 데이터를 갱신으로 변경

    try :
        # 온습도 값 받아서 MQTT로 전송
        temp = dhtDevice.temperature
        humd = dhtDevice.humidity
        print(f'{loop_num} - Temp:{temp}/humid:{humd}')

        origin_data = { 'DEV_ID' : dev_id,
                        'CURR_DT' : dt.datetime.now().strftime ( '%Y-%m-%d %H:%M:%S' ),
                        # strftime : 문자열로 변환
                        'TYPE' : 'TEMPHUMID', # 어떤 값인지 표현하기 위함
                        'VALUE' : f'{temp}|{humd}' # 들어오는 값
                       } # dictionary data
        pub_data = json.dumps(origin_data, ensure_ascii=False)

        mqttc.publish('pknu/data/', pub_data) # publish는 주제가 필요하다.
        loop_num += 1
    except RuntimeError as ex :
        print(ex.args[0])
    except KeyboardInterrupt:
        break

mqttc.loop_stop()
# 실행 끝