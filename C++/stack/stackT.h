//다양한 type에 대응하기 위해 template를 적용하여 구현
// 선언부와 구현부 모두 헤더파일에 존재해야 한다.
template <typename T>
class Stack
{
	T* buff;
	int idx =0; //idx 값을 할당해 주지않으면 쓰레기값이 지정되어있어 곤란할 지도..?

	public:
	Stack(int size){
		buff = new T[size];
	}
	~Stack(){
		delete[] buff;
	}
	void push(T n)
{	
	buff[idx++] = n;
}
	T pop ();
};
template<typename T>
T Stack<T>::pop()
{
	return buff[--idx];
}

