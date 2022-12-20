/**
* @file Program.cpp
* @description Kullanici arayüzünü olusturur, listeler üzerinde islemler yapilabilir hale gelir
* @course 2A
* @assignment Ödev 1
* @date 27.11.2022
* @author Fuad Garibli
*/

#include"Program.hpp"

Program::Program()
	{
		fileName = "veriler.txt";
		screenLimit = 8;
		width = 12;
		file = new DosyaOku(fileName);
		yListesi = file->getList();
		del = false;
	}
void Program::StartProgram()
	{
		int index = 0;
		while (yListesi->Count())
		{
			system("cls");
			PrintTop(index);
			PrintYoneticiNodes(index);
			PrintSatirNodes(index);
			index = CharControl(index);
		}
		system("cls");
		cout << "List is empty";
	}
void Program::PrintTop(int index)
{
	if (index < 8)
		cout << left << setw(4) << "ilk";
	else
		cout << left << setw(4) << "<---";
	if (((index / 8) + 1) * 8 < yListesi->Count())
	{
		cout << setw(8) << " ";
		AddSpacing(6);
		cout << right << setw(14) << "--->" << endl;
	}
	else
	{
		int count = yListesi->Count();
		if (count % 8 != 1)
		{
			int spacing = count % 8 - 2;
			if (count % 8 == 0) spacing = 6;
			cout << setw(8) << " ";
			AddSpacing(spacing);
			cout << right << setw(14) << "son" << endl;
		}
		else
			cout << setw(8) << right << "son" << endl;
	}
	
}
int Program::CharControl(int idx)
	{
		char ch;
		cin >> ch;
		int index = idx;
		if (!del)
		{
			if (ch == 'a')
				index -= 8;
			else if (ch == 'd')
				index += 8;
			else if (ch == 'z')
				index--;
			else if (ch == 'c')
				index++;
			else if (ch == 'p')
				yListesi->removeAt(index);
			else if (ch == 'k')
			{
				RandomAta(index);
				del = true;
			}
		}
		else
		{
			if (ch == 'k')
			{
				index = DeleteSatirNode(index);
				del = false;
			}
		}
		if (index < 0)
			index = 0;
		else if (index >= yListesi->Count())
			index = yListesi->Count() - 1;

		if (((index / 8) + 1) * 8 > yListesi->Count())
			screenLimit = yListesi->Count() % 8;
		else
			screenLimit = 8;
		return index;
	}
void Program::PrintYoneticiNodes(int index)
	{
		YoneticiDugum* start = yListesi->start();
		int page = index / 8;
		while (page--)
		{
			for (int i = 0; i < 8; i++)
				start = start->next;
		}
		YoneticiDugum* iter = start;
		for (int i = 0; i < screenLimit; i++)
		{
			cout << "  " << left << setw(10) << iter << "  ";
			iter = iter->next;
		}
		cout << endl;
		for (int i = 0; i < screenLimit; i++)
		{
			AddLineOfChar('-');
			cout << "  ";
		}
		cout << endl;
		iter = start;
		for (int i = 0; i < screenLimit; i++)
		{
			cout << "| " << right << setw(9) << iter->prev << "|  ";
			iter = iter->next;
		}
		cout << endl;
		for (int i = 0; i < screenLimit; i++)
		{
			AddLineOfChar('-');
			cout << "  ";
		}
		cout << endl;
		iter = start;
		for (int i = 0; i < screenLimit; i++)
		{
			cout << "| " << right << setw(9) << iter->data->ortalama << "|  ";
			iter = iter->next;
		}
		cout << endl;
		for (int i = 0; i < screenLimit; i++)
		{
			AddLineOfChar('-');
			cout << "  ";
		}
		cout << endl;
		iter = start;
		for (int i = 0; i < screenLimit; i++)
		{
			cout << "| " << right << setw(9) << iter->next << "|  ";
			iter = iter->next;
		}
		cout << endl;
		for (int i = 0; i < screenLimit; i++)
		{
			AddLineOfChar('-');
			cout << "  ";
		}
		cout << endl;
	}
void Program::PrintSatirNodes(int index)
	{
		cout << endl;
		YoneticiDugum* curNode = yListesi->start();
		for (int i = 0; i < index; i++)
			curNode = curNode->next;
		SatirListesi* sListesi = curNode->data;
		int spacing = index % 8;
		int count = sListesi->Count();
		SatirDugum* iter = sListesi->start();
		AddSpacing(spacing);
		AddLineOfChar('^');
		for (int i = 0; i < count; i++)
		{
			cout << endl;
			AddSpacing(spacing);
			cout << "  " << left << setw(10) << iter << "  " << endl;
			AddSpacing(spacing);
			AddLineOfChar('-');
			cout << endl;
			AddSpacing(spacing);
			cout << "| " << right << setw(9) << iter->data << "|  " << endl;
			AddSpacing(spacing);
			AddLineOfChar('-');
			if (del && i == random)
			{
				cout << "  <---- silinecek dugum";
			}
			cout << endl;
			AddSpacing(spacing);
			cout << "| " << right << setw(9) << iter->next << "|  " << endl;
			AddSpacing(spacing);
			AddLineOfChar('-');
			cout << endl;
			iter = iter->next;
		}
	}
void Program::AddSpacing(int spacing)
	{
		for (int i = 0; i < spacing; i++)
		{
			cout << "  ";
			for (int j = 0; j < width; j++)
				cout << " ";
		}
	}
void Program::AddLineOfChar(char c)
	{
		for (int i = 0; i < width; i++)
			cout << c;
	}
void Program::RandomAta(int index)
	{
		YoneticiDugum* iter = yListesi->start();
		for (int i = 0; i < index; i++)
			iter = iter->next;
		random = rand() % iter->data->Count();
	}
int Program::DeleteSatirNode(int index)
	{
		YoneticiDugum* iter = yListesi->start();
		for (int i = 0; i < index; i++)
			iter = iter->next;
		iter->data->removeAt(random);
		if (iter->data->Count() == 0)
		{
			yListesi->removeAt(index);
			index--;
		}
		else
		{
			SatirDugum* temp = iter->data->start();
			double prevOrtalama = iter->data->ortalama;
			double yeniOrtalama = 0;
			for (int i = 0; i < iter->data->Count(); i++)
			{
				yeniOrtalama += temp->data;
				temp = temp->next;
			}
			yeniOrtalama = yeniOrtalama / (double)iter->data->Count();
			iter->data->ortalama = yeniOrtalama;
			index = yListesi->UpdateNodePosition(iter, prevOrtalama, index);
		}
		return index;
	}
Program::~Program()
	{
		delete file;
	}
		