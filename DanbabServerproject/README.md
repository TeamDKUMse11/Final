# DanbabServerproject

13/05/2014

- 클라이언트에게 넘길 DB 샘플 작성
- DB샘플 전송 코드 (진행중)
	웹페이지 접속시 한글깨짐 문제 (텍스트 인코딩 utf8인데 왜 깨지는지 모르겠음)
	mobile-os.dankook에는 아직 프로그램 올리지 않아서 테스트 불가능

14/05/2014

- 한글 깨짐 해결
- DB샘플 json포멧으로 변경
- mobile-os.dankook.ac.kr:8998 로 접속시 기본적으로 해당 요일의 식단을 표시
	query에 file=Mon 입력시 월요일 식단 전송(Mon  Tue  Wed  Thu  Fir  Sat) 
	*********일요일에대한 처리 없음 (서버 죽을거니까 하지마시길)