#pragma once

#include<iostream>
#include<Windows.h>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>

#include"Client.h"
#include"VipClient.h"
#include"Amenities.h"
#include"VipAmenities.h"

class SpaSalon
{
private:
	vector<Amenities*> servises;
	vector<Client*> clients;
public:
	SpaSalon();

	SpaSalon(vector<Amenities*> servises, vector<Client*> clients);

	void BarSpa();

	bool BarClients(bool* exit);

	bool BarAmenities(bool* exit);

	void ChangeToUsual();

	SpaSalon(Amenities* servises, Client* clients);

	~SpaSalon();
};



SpaSalon::SpaSalon(){}

SpaSalon::SpaSalon(vector <Amenities*> servises, vector<Client*> clients)
{
	this->servises.assign(servises.begin(), servises.end());

	this->clients.assign(clients.begin(), clients.end());
}

SpaSalon::SpaSalon(Amenities* servises, Client* clients)
{
	this->servises.push_back(servises);
	this->clients.push_back(clients);
}

bool CompareNameUp(Client * a, Client *b)
{
	if (a->GetName() < b->GetName())
	{
		return true;
	}
	else
		return false;
}

void SpaSalon::BarSpa()
{
	bool exit = false;
	bool exitClients = true;
	bool exitAmenities = true;
	int sw1;

	while (!exit)
	{
		cout << "�������� ������� ����������:" <<endl;
		cout << "1. ������ � ���������." << endl;
		cout << "2. ������ � ��������." << endl;
		cout << "3. �����." << endl << endl;
		cin >> sw1;

		switch (sw1)
		{
		case 1:
		
			while (exitClients)
			{
				BarClients(&exitClients);
			}
			break;
		

		case 2:
		
			while (exitAmenities)
			{
				BarAmenities(&exitAmenities);
			}
			break;
		

		case 3:
		
			exit = true;
			break;
		

		default:
		
			cout << "������ �������� ����� ����." << endl;
			break;
		}
	}
	
}

bool SpaSalon::BarClients(bool* exit)
{
	int sw1, sw2, deposit, plus, numAmen;

	size_t  num;

	string name, flag;

	ChangeToUsual();

	cout << "\t�������� ������� ���������� ���������:" << endl;
	cout << "\t1. ����� ������������������ ��������." << endl;
	cout << "\t2. ���������� �������." << endl;
	cout << "\t3. �������� �������." << endl;
	cout << "\t4. ���������� � �������." << endl;
	cout << "\t5. ���������� ����� ��������." << endl;
	cout << "\t6. �������� ������." << endl;
	cout << "\t7. ��������� ������� �������." << endl;
	cout << "\t8. ���������� ��������." << endl;
	cout << "\t9. �����." << endl << endl;
	cin >> sw1;

	switch (sw1)
	{
	case 1:

		for (size_t i = 0; i < clients.size(); i++)
		{
			cout << "\t" << clients[i]->GetName() << ";" << clients[i]->GetDeposite() << endl;
		}
		cout << endl;

		break;


	case 2:

		cout << "\t\t ������� ��� �������:\n\t\t";

		while (cin.get() != '\n');
		getline(cin, name);

		cout << "\t\t ������� ����� ��������: \n\t\t";
		cin >> deposit;

		if (deposit > 500)
		{
			cout << "\t\t ������� ����� Vip ��������?: (��/���) \n\t\t";
			
			while (cin.get() != '\n');
			getline(cin, flag);

			if (flag == "��")
			{
				clients.push_back(new VipClient(deposit, name));
			}
			else
			{
				clients.push_back(new Client(deposit, name));
			}
		}

		break;


	case 3:

		cout << "\t\t�������� ����� ������� ��� ��������:\n\t\t";
		cin >> num;

		if (num > 0 && num < clients.size())
		{
			delete clients[num - 1]; //������� ��������

			clients.erase(clients.begin() + num - 1); // �������� � ����� ���������

			clients.shrink_to_fit(); // �������� ��� ������
		}
		else
		{
			cout << "\t\t������� � ����� ���������� ������� �� ����������.\n";
		}
		
		break;


	case 4:
		cout << "\t\t�������� ����� ������� ��� ������ ����������:\n\t\t";
		cin >> num;

		if (num > 0 && num < clients.size())
		{
			cout << "���: " << clients[num - 1]->GetName()
				<< "; �������: " << clients[num - 1]->GetDeposite() << " ���.; ������: "
				<< clients[num - 1]->GetSort() << "\n"
				<< "\t������ ��������� �����:" << endl;

			for (size_t i = 0; i < clients[num - 1]->GetAmenities().size(); i++)
			{
				//���������� ������ ������� � ����� �������� ����� �� �����
				cout << clients[num - 1]->GetAmenities()[i]->GetName() << endl;
			}
		}
		else
		{
			cout << "\t\t������� � ����� ���������� ������� �� ����������.\n";
		}

		break;


	case 5:
		cout << "\t\t�������� ����� ������� ��� ���������� ��������:\n\t\t";
		cin >> num;

		if (num > 0 && num < clients.size())
		{
			cout << "\t\t������� ����� ��� ���������� ��������:\n\t\t";
			cin >> plus;

			clients[num - 1]->SetDeposit(clients[num - 1]->GetDeposite() + plus);

			cout << "\t\t�������� ������� �������:"
				<< clients[num - 1]->GetName() << " ����������: "
				<< clients[num - 1]->GetDeposite() << endl;
		}
		else
		{
			cout << "\t\t������� � ����� ���������� ������� �� ����������.\n";
		}

		break;


	case 6:

		cout << "\t\t�������� ����� ������� ��� �������� ������:\n\t\t";
		cin >> num;

		if (num > 0 && num < clients.size())
		{
			cout << "\t\t������� ����� ������:\n\t\t";
			cin >> numAmen;

			cout << "\t\t �� ������������� ������ ������� " << clients[num - 1]->GetName()
				<< " ������ " << servises[numAmen - 1]->GetName() << "? (��/���) \n\t\t";

			while (cin.get() != '\n');
			getline(cin, flag);

			if (flag == "��" && servises[numAmen - 1]->GetCost() <= clients[num - 1]->GetDeposite())
			{
				// ����������� �������� �� ������ ������� � ������
				if ((clients[num - 1]->GetSort() == "VIP") ||
					(!servises[numAmen - 1]->IsVip() && clients[num - 1]->GetSort() == "usual"))
				{
					clients[num - 1]->SetAmenitie(servises[numAmen - 1]);
					cout << "\t\t������ �������!\n";
				}
				else
				{
					cout << "\t\t������ ������� ������ ���� VIP ��� �������� ������!\n\n";
				}
				
			}
			else if (flag == "��" && servises[numAmen - 1]->GetCost() > clients[num - 1]->GetDeposite())
			{
				cout << "\t\t������ �� � ��������� ��������� ������ �� �������� ������ ������. ����������, ��������� �������.\n";
			}
		}
		else
		{
			cout << "\t\t������� � ����� ���������� ������� �� ����������.\n";
		}

		break;


	case 7:

		cout << "\t\t�������� ����� ������� ��� ��������� �������:\n\t\t";
		cin >> num;

		if (num > 0 && num < clients.size())
		{
			if (clients[num - 1]->GetDeposite() >= 500)
			{
				VipClient* temp = new VipClient(clients[num - 1]->GetDeposite(),
												clients[num - 1]->GetName(),
												clients[num - 1]->GetAmenities());
				clients.insert(clients.begin() + (num - 1), temp);
			}
		}
		else
		{
			cout << "\t\t������� � ����� ���������� ������� �� ����������.\n";
		}

		break;


	case 8:

		cout << "\t\t1. ���������� �������� �� �����." << endl;
		cout << "\t\t2. ���������� �������� �� ������� ��������." << endl;
		cin >> sw2;

		switch (sw2)
		{
		case 1:
			sort(clients.begin(), clients.end(), CompareNameUp);
			cout << "\t\t���������� �� ����� �����������!.\n";
			break;

		case 2:
			sort(clients.begin(), clients.end());
			cout << "\t\t���������� �� ������� �������� �����������!.\n";
			break;

		default:
			break;
		}

		break;


	case 9:
		*exit = false;

		break;


	default:
		break;
	}

	
	return *exit;
}

bool SpaSalon::BarAmenities(bool* exit)
{
	int sw1, sw2, cost;

	size_t  num;

	string name, flag;

	Amenities* temp = NULL;

	VipAmenities* vTemp = NULL;

	cout << "\t1. ����� ������ �����." << endl;
	cout << "\t2. ���������� ������." << endl;
	cout << "\t3. �������� ������." << endl;
	cout << "\t4. �������������� ������." << endl;
	cout << "\t5. �����." << endl << endl;
	cin >> sw1;

	switch (sw1)
	{
	case 1:
		
		for (size_t i = 0; i < servises.size(); i++)
		{
			cout << "\t" << servises[i]->GetName() << ";" << servises[i]->GetCost() << endl;
		}
		cout << endl;

		break;

	case 2:

		cout << "\t\t ������� ������������ ������:\n\t\t";

		while (cin.get() != '\n');
		getline(cin, name);

		cout << "\t\t ������� � ���������: \n\t\t";
		cin >> cost;
		
		cout << "\t\t1. ������� ������.\n";
		cout << "\t\t2. VIP ������.\n\t\t";
		cin >> sw2;

		switch (sw2)
		{
			
		case 1:

			temp = new Amenities(name, cost);

			servises.push_back(temp);
			
			cout << "\t\t������ ���������.\n";

			break;

		case 2:

			vTemp = new VipAmenities(name, cost);

			servises.push_back(vTemp);

			cout << "\t\tVip ������ ���������.\n";

			break;

		default:
			cout << "\t\t������ �������� ����� ����." << endl;
			break;
		}

		break;

	case 3:

		cout << "\t\t�������� ����� ������ ��� ��������:\n\t\t";
		cin >> num;

		if (num > 0 && num < servises.size())
		{
			delete servises[num - 1]; //������� ��������

			servises.erase(servises.begin() + num - 1); // �������� � ����� ���������

			servises.shrink_to_fit(); // �������� ��� ������
		}
		else
		{
			cout << "\t\t������ � ����� ���������� ������� �� ����������.\n";
		}

		break;

	case 4:

		cout << "\t\t�������� ����� ������ ��� ��������������:\n\t\t";
		cin >> num;

		if (num > 0 && num < servises.size())
		{
			cout << "\t\t ������� ������������ ������:\n\t\t";

			while (cin.get() != '\n');
			getline(cin, name);

			cout << "\t\t ������� � ���������: \n\t\t";
			cin >> cost;

			cout << "\t\t1. ������� ������.\n";
			cout << "\t\t2. VIP ������.\n\t\t";
			cin >> sw2;

			switch (sw2)
			{

			case 1:

				temp = new Amenities(name, cost);

				servises.insert(servises.begin() + (num - 1), temp);

				cout << "\t\t������ ���������.\n";

				break;

			case 2:

				vTemp = new VipAmenities(name, cost);

				servises.insert(servises.begin() + (num - 1), vTemp);

				cout << "\t\tVip ������ ���������.\n";

				break;

			default:
				cout << "\t\t������ �������� ����� ����." << endl;
				break;
			}
		}
		else
		{
			cout << "\t\t������ � ����� ���������� ������� �� ����������.\n";
		}

		break;

	case 5:
		
		*exit = false;
		break;

	default:
		cout << "������ �������� ����� ����." << endl;
		break;
	}

	
	return *exit;
}


void SpaSalon::ChangeToUsual()
{
	for (size_t i = 0; i < clients.size(); i++)
	{
		if ( (clients[i]->GetDeposite() < 500) && (clients[i]->GetSort() == "VIP") )
		{
			Client* temp = new Client(clients[i]->GetDeposite(),
				clients[i]->GetName(),
				clients[i]->GetAmenities());
			clients.insert(clients.begin() + i, temp);
		}
	}

}

SpaSalon::~SpaSalon()
{
	for (size_t i = 0; i < servises.size(); i++)
	{
		delete servises[i];
	}

	for (size_t i = 0; i < clients.size(); i++)
	{
		delete clients[i];
	}

	clients.clear();
	servises.clear();

	clients.shrink_to_fit();
	servises.shrink_to_fit();
}
