//public을 상단, private를 하단에 배치=> 사용자 친화적
class Stack
{
	public:
		Stack(int size);
		~Stack();
		void push(int n);
		int pop();

	private:
		int* buf;
		int idx;

};
