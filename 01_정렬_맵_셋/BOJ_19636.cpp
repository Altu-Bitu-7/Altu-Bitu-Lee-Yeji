#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int w0, a0, i0, t, d, i, a, b;
	int w1, w2;

	bool d1_flag = false, d2_flag = false, y_flag= false;

	// �Է�
	cin >> w0 >> i0 >> t >> d >> i >> a;

	w1 = w0; w2 = w0;

	// ���� ��緮�� ���뷮�� ����
	b = i0;

	// ����(���� ��緮�� ������ �ʴ� ���)
	for (int j = 0; j < d; j++)
	{
		int gain1 = i - (a + i0);
		w1 += gain1;

		if (w1 <= 0) {
			d1_flag = true;
			break;
		}
	}

	// ����(���� ��緮�� ���ϴ� ���)
	for(int j= 0; j < d; j++)
	{	
		int gain2 = i - (a + b);
		w2 += gain2;

		// ���� ��緮 ��ȭ ��ġ �ʰ�
		// gain �տ� - �޾������
		if (-gain2 > t)
			b += floor(gain2 / 2.0);

		if (w2 <= 0 || b <= 0)
			d2_flag = true;
	}


	if (i0 > b)
		y_flag = true;


	if (d1_flag) 
		cout << "Danger Diet" << "\n";
	else
		cout << w1 << " " <<  i0 << "\n";

	if (d2_flag) {
		cout << "Danger Diet";
	}
	else {
		if (y_flag)
			cout << w2 << " " << b << " " << "YOYO";
		else
			cout << w2 << " " << b << " " << "NO";
	}

	return 0;
}