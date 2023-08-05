#include <iostream>

class Animal { // 클래스!! 객체를 생성하는 '틀'이다.
 private:
  int food;
  int weight;

 public:
  void set_animal(int _food, int _weight) { // 딱봐도 얘는 생성자군.
    food = _food;
    weight = _weight;
  }
	
  void increase_food(int inc) {
    food += inc;
    weight += (inc / 3);
  }
  void view_stat() {
    std::cout << "이 동물의 food   : " << food << std::endl;
    std::cout << "이 동물의 weight : " << weight << std::endl;
  }
};  // 세미콜론 잊지 말자!


/*

숙제 1

*/

const int MONTH_LENGTH[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
const int NUM_OF_MONTH_IN_YEAR = 12;

class Date {
	// 아무것도 안적으면 자동 private
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date)
  {
	  year_ = year;
	  month_ = month;
	  day_ = date;
  }
	
  void AddDay(int inc)
  {
	  day_+=inc;
	  if(MONTH_LENGTH[month_] < day_)
	  {
		  month_+= day_ / MONTH_LENGTH[month_];
		  day_ %= MONTH_LENGTH[month_];
	  }
	  
	  if(month_ > NUM_OF_MONTH_IN_YEAR)
	  {
		  year_+= month_ / NUM_OF_MONTH_IN_YEAR;
		  month_ %= NUM_OF_MONTH_IN_YEAR;
	  }
  }
  void AddMonth(int inc)
  {
	  month_+=inc;
	  
	  if(month_ > NUM_OF_MONTH_IN_YEAR)
	  {
		  year_+= month_ / NUM_OF_MONTH_IN_YEAR;
		  month_ %= NUM_OF_MONTH_IN_YEAR;
	  }
	  
  }
	
  void AddYear(int inc)
  {
	  year_ += inc;
  }

  void ShowDate()
  {
	  std::cout<<"year = "<<year_<<'\n';
	  
	  std::cout<<"month = "<<month_<<'\n';
	  
	  std::cout<<"day = "<<day_<<'\n';
  }
};





int main() {
  	Animal animal;
  	animal.set_animal(100, 50);
  	animal.increase_food(30);

  	animal.view_stat();
	
  	Date date;
	date.SetDate(2002,9,6);
	date.ShowDate();
	date.AddDay(30);
	date.ShowDate();
	date.AddMonth(3);
	date.ShowDate();
	date.AddYear(1);
	date.ShowDate();

	
  return 0;
}

/*
클래스 상에 있는 녀석들은 멤버 변수, 그리고 멤버 함수이다.

클래스를 통해 만들어진 '인스턴스' 속에는 멤버 변수,함수 라는 틀을 통해 만들어진 인스턴스 변수, 함수가 들어있다.
*/
