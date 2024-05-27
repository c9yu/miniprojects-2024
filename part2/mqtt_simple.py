import paho.mqtt.client as mqtt
import time

loop_num = 0

def onConnect(client, userdata, flags, reason_code, properties):
    print(f'Connected result code : {reason_code}')
    client.subscribe('pknu67/rcv')

def onMessage(client, userdata, msg):
    print(f'{msg.topic} + {msg.payload}')

mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2) # 2023.09 이후 버전업
mqttc.on_connect = onConnect # 접속시 이벤트
mqttc.on_message = onMessage # 메시지 출력

# 192.168.5.3 자신의 ip 입력
mqttc.connect('192.168.5.2', 1883, 60) # 60초 안에 실행안되면 종료하겠다.

mqttc.loop_start() # 영원히 돌린다.
while True:
    mqttc.publish('pknu67/data', loop_num) # publish는 주제가 필요하다.
    loop_num += 1
    time.sleep(1)

mqttc.loop_stop()