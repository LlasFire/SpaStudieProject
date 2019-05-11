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
		cout << "Выберите подменю управления:" <<endl;
		cout << "1. Работа с клиентами." << endl;
		cout << "2. Работа с услугами." << endl;
		cout << "3. Выход." << endl << endl;
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
		
			cout << "Выбран неверный пункт меню." << endl;
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

	cout << "\tВыберите подменю управления клиентами:" << endl;
	cout << "\t1. Вывод зарегистрированных клиентов." << endl;
	cout << "\t2. Добавление клиента." << endl;
	cout << "\t3. Удаление клиента." << endl;
	cout << "\t4. Информация о клиенте." << endl;
	cout << "\t5. Пополнение счёта клиентом." << endl;
	cout << "\t6. Оказание услуги." << endl;
	cout << "\t7. Изменение статуса клиента." << endl;
	cout << "\t8. Сортировка клиентов." << endl;
	cout << "\t9. Выход." << endl << endl;
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

		cout << "\t\t Введите имя клиента:\n\t\t";

		while (cin.get() != '\n');
		getline(cin, name);

		cout << "\t\t Введите сумму депозита: \n\t\t";
		cin >> deposit;

		if (deposit > 500)
		{
			cout << "\t\t Желаете стать Vip клиентом?: (да/нет) \n\t\t";
			
			while (cin.get() != '\n');
			getline(cin, flag);

			if (flag == "да")
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

		cout << "\t\tВыберите номер клиента для удаления:\n\t\t";
		cin >> num;

		if (num > 0 && num < clients.size())
		{
			delete clients[num - 1]; //очистка элемента

			clients.erase(clients.begin() + num - 1); // удаление и сдвиг указателя

			clients.shrink_to_fit(); // подгонка под размер
		}
		else
		{
			cout << "\t\tКлиента с таким порядковым номером не существует.\n";
		}
		
		break;


	case 4:
		cout << "\t\tВыберите номер клиента для вывода информации:\n\t\t";
		cin >> num;

		if (num > 0 && num < clients.size())
		{
			cout << "Имя: " << clients[num - 1]->GetName()
				<< "; Депозит: " << clients[num - 1]->GetDeposite() << " руб.; Статус: "
				<< clients[num - 1]->GetSort() << "\n"
				<< "\tСписок оказанных услуг:" << endl;

			for (size_t i = 0; i < clients[num - 1]->GetAmenities().size(); i++)
			{
				//вытягиваем вектор клиента и выдаём название услуг по одной
				cout << clients[num - 1]->GetAmenities()[i]->GetName() << endl;
			}
		}
		else
		{
			cout << "\t\tКлиента с таким порядковым номером не существует.\n";
		}

		break;


	case 5:
		cout << "\t\tВыберите номер клиента для пополнения депозита:\n\t\t";
		cin >> num;

		if (num > 0 && num < clients.size())
		{
			cout << "\t\tВведите сумму для пополнения депозита:\n\t\t";
			cin >> plus;

			clients[num - 1]->SetDeposit(clients[num - 1]->GetDeposite() + plus);

			cout << "\t\tИтоговый депозит клиента:"
				<< clients[num - 1]->GetName() << " составляет: "
				<< clients[num - 1]->GetDeposite() << endl;
		}
		else
		{
			cout << "\t\tКлиента с таким порядковым номером не существует.\n";
		}

		break;


	case 6:

		cout << "\t\tВыберите номер клиента для оказания услуги:\n\t\t";
		cin >> num;

		if (num > 0 && num < clients.size())
		{
			cout << "\t\tВведите номер услуги:\n\t\t";
			cin >> numAmen;

			cout << "\t\t Вы действительно хотите оказать " << clients[num - 1]->GetName()
				<< " услуги " << servises[numAmen - 1]->GetName() << "? (да/нет) \n\t\t";

			while (cin.get() != '\n');
			getline(cin, flag);

			if (flag == "да" && servises[numAmen - 1]->GetCost() <= clients[num - 1]->GetDeposite())
			{
				// комплексная проверка на статус клиента и услуги
				if ((clients[num - 1]->GetSort() == "VIP") ||
					(!servises[numAmen - 1]->IsVip() && clients[num - 1]->GetSort() == "usual"))
				{
					clients[num - 1]->SetAmenitie(servises[numAmen - 1]);
					cout << "\t\tУслуга оказана!\n";
				}
				else
				{
					cout << "\t\tСтатус клиента должен быть VIP для оказания услуги!\n\n";
				}
				
			}
			else if (flag == "да" && servises[numAmen - 1]->GetCost() > clients[num - 1]->GetDeposite())
			{
				cout << "\t\tКлиент не в состоянии выполнить оплату по оказанию данной услуги. Пожалуйста, пополните депозит.\n";
			}
		}
		else
		{
			cout << "\t\tКлиента с таким порядковым номером не существует.\n";
		}

		break;


	case 7:

		cout << "\t\tВыберите номер клиента для изменения статуса:\n\t\t";
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
			cout << "\t\tКлиента с таким порядковым номером не существует.\n";
		}

		break;


	case 8:

		cout << "\t\t1. Сортировка клиентов по имени." << endl;
		cout << "\t\t2. Сортировка клиентов по размеру депозита." << endl;
		cin >> sw2;

		switch (sw2)
		{
		case 1:
			sort(clients.begin(), clients.end(), CompareNameUp);
			cout << "\t\tСортировка по имени произведена!.\n";
			break;

		case 2:
			sort(clients.begin(), clients.end());
			cout << "\t\tСортировка по размеру депозита произведена!.\n";
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

	cout << "\t1. Вывод списка услуг." << endl;
	cout << "\t2. Добавление услуги." << endl;
	cout << "\t3. Удаление услуги." << endl;
	cout << "\t4. Редактирование услуги." << endl;
	cout << "\t5. Выход." << endl << endl;
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

		cout << "\t\t Введите наименование услуги:\n\t\t";

		while (cin.get() != '\n');
		getline(cin, name);

		cout << "\t\t Введите её стоимость: \n\t\t";
		cin >> cost;
		
		cout << "\t\t1. Простая услуга.\n";
		cout << "\t\t2. VIP услуга.\n\t\t";
		cin >> sw2;

		switch (sw2)
		{
			
		case 1:

			temp = new Amenities(name, cost);

			servises.push_back(temp);
			
			cout << "\t\tУслуга добавлена.\n";

			break;

		case 2:

			vTemp = new VipAmenities(name, cost);

			servises.push_back(vTemp);

			cout << "\t\tVip услуга добавлена.\n";

			break;

		default:
			cout << "\t\tВыбран неверный пункт меню." << endl;
			break;
		}

		break;

	case 3:

		cout << "\t\tВыберите номер услуги для удаления:\n\t\t";
		cin >> num;

		if (num > 0 && num < servises.size())
		{
			delete servises[num - 1]; //очистка элемента

			servises.erase(servises.begin() + num - 1); // удаление и сдвиг указателя

			servises.shrink_to_fit(); // подгонка под размер
		}
		else
		{
			cout << "\t\tУслуги с таким порядковым номером не существует.\n";
		}

		break;

	case 4:

		cout << "\t\tВыберите номер услуги для редактирования:\n\t\t";
		cin >> num;

		if (num > 0 && num < servises.size())
		{
			cout << "\t\t Введите наименование услуги:\n\t\t";

			while (cin.get() != '\n');
			getline(cin, name);

			cout << "\t\t Введите её стоимость: \n\t\t";
			cin >> cost;

			cout << "\t\t1. Простая услуга.\n";
			cout << "\t\t2. VIP услуга.\n\t\t";
			cin >> sw2;

			switch (sw2)
			{

			case 1:

				temp = new Amenities(name, cost);

				servises.insert(servises.begin() + (num - 1), temp);

				cout << "\t\tУслуга добавлена.\n";

				break;

			case 2:

				vTemp = new VipAmenities(name, cost);

				servises.insert(servises.begin() + (num - 1), vTemp);

				cout << "\t\tVip услуга добавлена.\n";

				break;

			default:
				cout << "\t\tВыбран неверный пункт меню." << endl;
				break;
			}
		}
		else
		{
			cout << "\t\tУслуги с таким порядковым номером не существует.\n";
		}

		break;

	case 5:
		
		*exit = false;
		break;

	default:
		cout << "Выбран неверный пункт меню." << endl;
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
