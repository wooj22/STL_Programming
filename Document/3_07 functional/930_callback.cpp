//콜벡 구현
//		람다와 같이 쓰면 콜백을 받아 후에 전달받을 결과에 따라 코드를 진행하도록 코딩하는 것이 가능

#include <functional>   
#include <iostream>
#include <string>
using namespace std;

void callback_func(function<void(string)> fn) {
	fn("yes");										// 2. 콜백 호출
	//fn("no");										// 2. 콜백 호출
}

int main() {

	callback_func(									// 1. 람다 전달
		[](string s)-> void {
			if (s == "yes") cout << "yes";			// 3. 결과에 따라 처리
			if (s == "no") cout << "no";
		}
	);
}

/*
// 콜백을 이용하여 팝업 결과를 받아 처리하기

#include <functional>
#include <iostream>
#include <string>
using namespace std;

class Popup {
	string massage = "";
	function<void(string)> callback;
public:
	void Show(string msg, function<void(string)> fn)
	{
		massage = msg;
		callback = fn;
	}
	void OnClick_yes() {	callback("yes");	}
	void OnClick_no() {		callback("no");		}
};

int main() 
{
	Popup pop;
	pop.Show("선택하세요", [](string s)-> void {
		if (s == "yes") cout << "yes";			// 3. 결과에 따라 처리
		if (s == "no") cout << "no";
		});

	//pop.OnClick_yes();
	//pop.OnClick_no();
}


*/