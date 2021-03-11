class Stack
{
	private:
		int* buf;
		int idx;

	public:
		Stack(int size);
		~Stack();
		void push(int n);
		int pop();
};
