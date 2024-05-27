# 미니프로젝트-1 2024
라즈베리 파이를 이용한 도서 관리 프로그램

- 








# 미니프로젝트-2 2024
Iot 개발자 미니프로젝트 리포지토리

## 1일차 (2024-05-14)
- 조별 자리 배치
- IoT 프로젝트 개요

    ![IoT 프로젝트](https://raw.githubusercontent.com/c9yu/miniprojects-2024/main/imgs/pr001.png)
    1. IoT 기기 구성 - 아두이노, 라즈베리 파이 등 IoT 장비들과 연결
    2. 서버 구성 - IoT 기기와 통신, DB 구성, 데이터 수집 앱 개발
    3. 모니터링 구성 - 실시간 모니터링/제어 앱, 전체 연결

- 조별 미니프로젝트
    - 5월28일 (40시간)
    - 구체적으로 어떤 디바이스 구성, 데이터 수집, 모니터링 계획
    - 8월 말 정도에 끝나는 프로젝트 일정 계획
    - 요구사항 리스트, 기능 명세, UI/UX 디자인, DB 설계 -> 문서 하나로 통합하여 작성
    - 5월 28일 오후 각 조별로 파워포인트/프레젠테이션 10분 발표
    - 요구사항 리스트 문서전달
    - 기능명세 문서
    - DB 설계 ERD 또는 SSMS 물리적 DB 설계
    - UI/UX 디자인 5/16에 내용 전달


## 2일차 (2024-05-16)
- 미니 프로젝트
    - 프로젝트 문서
    - UI/UX 디자인 툴 설명
        - 오븐, https://ovenapp.io/ 
        - 피그마, https://www.figma.com/
            - 개발자를 위한 피그마 튜토리얼, 
                - https://www.figma.com/design/MtgbuSF8Qqctl3JXobfnm5/%EA%B0%9C%EB%B0%9C%EC%9E%90%EB%A5%BC-%EC%9C%84%ED%95%9C-%ED%94%BC%EA%B7%B8%EB%A7%88-%ED%8A%9C%ED%86%A0%EB%A6%AC%EC%96%BC-(Community)?m=dev&t=DR1U3GDIhYwS1Xoa-1
            - 피그마 단축키
            - V - 선택도구
            - A - 직선도구
            - T - 텍스트도구
            - Space + Drag - 마우스 커서에 따라 원하는 영역으로 이동
            - Ctrl + R - 레이어 이름 변경
            - Ctrl + G - 객체 그룹화
            - Ctrl + Shift + G - 객체 그룹 해제
            - Ctrl + D - 선택한 객체 복사
            - Ctrl + [ - 선택한 객체 뒤로 보내기
            - Ctrl + ] - 선택한 객체 앞으로 보내기
        - 모굽스, https://app.moqups.com/

    - 프리젠테이션
        - 미리캔버스, https://www.miricanvas.com/ko

    - Notion 팀 프로젝트 템플릿 활용
    - 라즈베리 파이(RPi) 리셋팅, 네트워크 설정, VNC(OS UI 작업)
    - 컴퓨터 원격 데스크탑 앱
        - 애니데스크, https://anydesk.com/ko/
        - 크롭 리모트데스트탑, https://remotedesktop.google.com/?hl=ko&pli=1
        - VNC, https://www.realvnc.com/en/connect/download/viewer/

- 스마트홈 연동 클래스 미니 프로젝트
    1.  요구사항 정의, 기능 명세, 일정 정리
    2.  UI/UX 디자인
    3.  DB 설계
    4.  RPi 셋팅 (네트워크 셋팅)
    5.  RPi GPIO에 IoT 디바이스 연결 (카메라, HDT(온/습도 센서), RGB LED, ...)
    6.  RPi 데이터 전송 파이썬 프로그래밍
    7.  PC(Server) 데이터 수신 C# 프로그래밍 작성
    8.  모니터링 앱 개발 (수신 및 송신)

## 3일차 (2024-05-20)
- 미니 프로젝트
    - 실무 프로젝트 문서
    - jira 사용법
    - 조별 프로젝트 진행

- 라즈베리 파이 셋팅
    1. RPi 기본 구성 - RPi 
    2. RPi 기본 셋팅
        - [x]최신 업그레이드
        - [x]한글화
        - [x]키보드 변경
        - [x]화면 사이즈 변경 (Real VNC)
        - [x]Pi Apps 앱설치 도우미 앱
        - [x]Github Desktop, VS Code 
        - [x]네트워크 확인
        - [ ]RealVNC Server 자동실행 설정 - 할 필요 없음

- 스마트홈 연동 클래스 미니프로젝트
    - 라즈베리 파이 (RPi) 셋팅 ...

## 4일차 (2024-05-21)
- 라즈베리 파이 IoT 장비 설치
    - [x] 라즈베리 파이 카메라 : sudo libcamera-hello -t 0
    - [x] GPIO HAT
    - [ ] 브레드보드와 연결
    - [x] DHT11 센서
    - [x] RGB LED 모듈 연결
        V : 5V
        R : GPIO04 연결
        G : GOUI05 연결
        B : GOUI06 연결
    - [ ] 서보모터


## 5일차 (2024-05-22)
- 라즈베리 파이 IoT 장비 설치
    [x] DHT11 센서
        - GND : GND 8개 중 아무곳에나 연결
        - VCC : 5V에 연결
        - S : GPIO18에 연결

## 6, 7일차 (2024-05-23)
- 라즈베리 파이 IoT 장비 설치
    - 서보모터의 경우 서보모터 모듈을 사용해야 떨림을 막을 수 있음

- 네트워크 대공사
    - [x] 개인 공유기, PC, 라즈베리 파이

- 스마트홈 연동 클래스 미니 프로젝트
    - 온습도 센서, RGB LED
    - RPi <--> Windows 통신(MQTT)
    - WPF 모니터링 앱

- IoT 기기간 통신방법
    - Modbus : 시리얼 통신으로 데이터 전송 (완전 구식)
    - OPC UA : Modbus통신의 불편한 점을 개선 (매우 복잡)
    - **MQTT** : 가장 편리하며 AWS, IoT, Azure IoT 클라우드 산업계 표준으로 사용

- 데이터 전달 프로세스
    - Publisher : 데이터를 만들어 Broker에 전달한다.
    - Broker : Publisher에게 받은 데이터 중 Subscriber 요구하는 데이터를 전달한다.
    - Publisher와 Subscriber의 관계는 고정적이지 않다.
        - 윈도우가 Publisher나 Subscriber 역할을 하거나 RPi가 Publisher나 Subscriber 역할을 역할을 할 수도 있다.

- MQTT 설정
    - https://mosquitto.org/ 를 통해 설치
    - listener 1883 0.0.0.0으로 변경
        ```
        listener port-number [ip address/host name/unix socket path]
        listener 1883 0.0.0.0
        ```
    - allow_anonymous true으로 변경
        ```
        allow_anonymous false 를
        allow_anonymous true 로 변경
        ```
    - 윈도우 -> 서비스 앱에서 Mosquitto Broker 속성에서 시작 유형을 '자동'으로 변경
    - 고급 보안이 포함된 방화벽
        - 새 규칙 -> 규칙 종류: 포트 -> TCP, 특정 로컬 포트 : 1883 -> 연결 허용 -> 도메인, 개인, 공용 전부 체크
        -> 이름 및 설명 작성 (ex. 이름: MQTT 방화벽, 설명: 1833 방화벽 열기)

    - https://mqtt-explorer.com/ 를 설치하여 연결을 확인
        - New Connections
            - 

- MQTT 통신
    - Mosquitto Broker 설치
    - RPi : paho-mqtt 패키지 설치, 송신 (publisher)
    - Win : MQTT Explorer를 통해 수신된 데이터를 확인 가능 (Subscriber)

    - 반대로 MQTT Explorer에서 RPi로 데이터를 보내는 것도 가능
    

## 9일차 (2024-05-27)


## 8일차 (2024-05-23)


## 9일차 (2024-05-24)


## 10일차 (2024-05-27)


