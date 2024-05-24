# Red led
import RPi.GPIO as GPIO
import time # 작동 시간을 관리

# RGB LED 핀 번호 셋팅
red_pin = 4 # GPIO 핀 번호
green_pin = 6
blue_pin = 5

GPIO.setmode(GPIO.BCM) # GPIO 04 와 같이 이름붙여진 번호를 사용하겠다.
# GPIO.BOARD 의 경우 각 핀에 지정되어 있는 번호를 사용하겠다.

GPIO.setup(red_pin, GPIO.OUT) # 4번 핀으로 output 출력하겠다. == 불이 켜짐
GPIO.setup(green_pin, GPIO.OUT)
GPIO.setup(blue_pin, GPIO.OUT)

try:
    while (True):
        GPIO.output(red_pin, False)
        GPIO.output(green_pin, False)
        GPIO.output(blue_pin, False)
        time.sleep(1) # 0.5sec // Red
        # 0.5초 동안 불이 켜진다

        GPIO.output(red_pin, False)
        GPIO.output(green_pin, True)
        GPIO.output(blue_pin, False)
        time.sleep(0.5) # 0.5sec // Green

        GPIO.output(red_pin, False)
        GPIO.output(green_pin, False)
        GPIO.output(blue_pin, True)
        time.sleep(0.5) # 0.5sec // Blue

        GPIO.output(red_pin, True)
        GPIO.output(green_pin, True)
        GPIO.output(blue_pin, True)
        time.sleep(1) # 0.5sec // White
        # 0.5초 동안 불이 꺼진다
except KeyboardInterrupt:
    GPIO.cleanup()