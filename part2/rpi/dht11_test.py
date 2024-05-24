# dht11_test.py
import adafruit_dht
import time
import RPi.GPIO as GPIO
import board

log_num = 0
sensor_pin = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.IN) # LED와 달리 값을 받아야 하므로 GPIO.OUT이 아닌 GPIO.IN
dhtDevice = adafruit_dht.DHT11(board.D18)

while (True):
    try:
        temp = dhtDevice.temperature
        humid = dhtDevice.humidity
        print(f'{log_num} - Temp : {temp}c / Humid : {humid}%')
        log_num += 1
        time.sleep(2)
    except RuntimeError as ex:
        print(ex.args[0])
    except KeyboardInterrupt:
        break

dhtDevice.exit()