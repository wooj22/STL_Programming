
//특정 자료형 input 변수의 상하한 값을 제한하는 코드를 작성하라.

int main(int argc, const char * argv[]) 
{
    int input;
    cin>>input;

    if (input > 100) { 		//상한값 100 체크
	input = 100;
    }
    if (input < 0) {		//하한값 0 체크
	input = 0;
    }

    cout<< input <<endl;
}


/*

int main(int argc, const char * argv[]) {
    int input;
    cin>>input;
    
    input = checkMinMax<int>(input, 0, 100);
    
    cout<<input<<endl;
    
    return 0;
}


template <typename T>
T checkMinMax(T x, T min, T max) {
    return std::min(std::max(x, min), max);
}

/*