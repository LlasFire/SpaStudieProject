#include<iostream>
#include<Windows.h>
#include<string>
#include <iomanip>
#include<vector>
#include<algorithm>

#include"Client.h"
#include"VipClient.h"
#include"Amenities.h"
#include"VipAmenities.h"
#include"SpaSalon.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Amenities*> amen = 
	{
		new Amenities("�������", 10),
		new Amenities("�����", 12),
		new Amenities("������", 15),

		new VipAmenities("������� ������", 25),
		new VipAmenities("�������� ����", 17),
		new VipAmenities("�������", 20)
	};

	vector<Client*> clients =
	{
		new Client(280, "Fred"),
		new Client(400, "George"),
		new Client(560, "David"),

		new VipClient(760,"Michaella"),
		new VipClient(590, "Julia"),
		new VipClient(1265, "Leonard")
	};

	SpaSalon* salon_1 = new SpaSalon(amen, clients);

	salon_1->BarSpa();

	delete salon_1;

	clients.clear();
	amen.clear();

	clients.shrink_to_fit();
	amen.shrink_to_fit();

	system("pause");
	return 0;
}