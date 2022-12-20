/**
* @file YoneticiListesi.cpp
* @description "Veriler.txt" deki her bir satiri ortalamasina göre siralayarak saklayan çift yönlü bagli liste
* @course 2A
* @assignment Ödev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#include"YoneticiListesi.hpp"

	YoneticiDugum* YoneticiListesi::FindPreviousByPosition(int index)throw(NoSuchElement) {
		if (index < 0 || index > size) throw NoSuchElement("No Such Element");
		YoneticiDugum* prv = head;
		int i = 1;
		for (YoneticiDugum* itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
			prv = prv->next;
		}
		return prv;
	}
	YoneticiListesi::YoneticiListesi() {
		head = NULL;
		size = 0;
	}
	YoneticiDugum* YoneticiListesi::start()
	{
		return head;
	}
	int YoneticiListesi::Count()const {
		return size;
	}
	bool YoneticiListesi::isEmpty()const {
		return size == 0;
	}
	void YoneticiListesi::add(SatirListesi* item) {
		insert(size, item);
	}
	void YoneticiListesi::insert(int index, SatirListesi* item) {
		if (index < 0 || index > size) throw "Index out of Range";
		if (index == 0) {
			head = new YoneticiDugum(item, head);
			if (head->next != NULL) head->next->prev = head;
		}
		else {
			if (item->ortalama < head->data->ortalama)
			{
				YoneticiDugum* newNode = new YoneticiDugum(item, head);
				newNode->next->prev = newNode;
				head = newNode;
			}
			else
			{
				YoneticiDugum* prv = head;
				while (prv->next != NULL && item->ortalama > prv->next->data->ortalama)
					prv = prv->next;
				prv->next = new YoneticiDugum(item, prv->next, prv);
				if (prv->next->next != NULL)
					prv->next->next->prev = prv->next;
			}
		}
		size++;
	}
	SatirListesi* YoneticiListesi::first()throw(NoSuchElement) {
		if (isEmpty()) throw NoSuchElement("No Such Element");
		return head->data;
	}
	SatirListesi* YoneticiListesi::last()throw(NoSuchElement) {
		if (isEmpty()) throw NoSuchElement("No Such Element");
		return FindPreviousByPosition(size)->data;
	}
	int YoneticiListesi::indexOf(SatirListesi* item)throw(NoSuchElement) {
		int index = 0;
		for (YoneticiDugum* itr = head; itr != NULL; itr = itr->next) {
			if (itr->data == item) return index;
			index++;
		}
		throw NoSuchElement("No Such Element");
	}
	void YoneticiListesi::remove(SatirListesi* item) {
		int index = indexOf(item);
		removeAt(index);
	}
	void YoneticiListesi::removeAt(int index) {
		if (index < 0 || index >= size) throw "Index out of Range";
		YoneticiDugum* del;
		if (index == 0) {
			del = head;
			head = head->next;
			if (head != NULL) head->prev = NULL;
		}
		else {
			YoneticiDugum* prv = FindPreviousByPosition(index);
			del = prv->next;
			prv->next = del->next;
			if (del->next != NULL)
				del->next->prev = prv;
		}
		size--;
		delete del;
	}
	bool YoneticiListesi::find(SatirListesi* item) {
		for (YoneticiDugum* itr = head; itr != NULL; itr = itr->next) {
			if (itr->data == item) return true;
		}
		return false;
	}
	void YoneticiListesi::reverse() {
		for (YoneticiDugum* itr = head; itr != NULL;) {
			YoneticiDugum* tmp = itr->next;
			itr->next = itr->prev;
			itr->prev = tmp;
			if (tmp == NULL) {
				head = itr;
				break;
			}
			itr = tmp;
		}
	}
	SatirListesi* YoneticiListesi::elementAt(int index)throw(NoSuchElement) {
		if (index < 0 || index >= size) throw NoSuchElement("No Such Element");
		if (index == 0) return head->data;
		return FindPreviousByPosition(index)->next->data;
	}
	void YoneticiListesi::clear() {
		while (!isEmpty())
			removeAt(0);
	}
	ostream& operator<<(ostream& screen, YoneticiListesi& rgt) {
		for (YoneticiDugum* itr = rgt.head; itr != NULL; itr = itr->next) {
			screen << itr->data->ortalama << endl;
		}
		screen << endl;
		return screen;
	}
	void YoneticiListesi::printNodesFromPositionInReverseOrder(int index)throw(NoSuchElement) {
		if (index < 0 || index >= size) throw NoSuchElement("No Such Element");
		for (YoneticiDugum* itr = FindPreviousByPosition(index + 1); itr != NULL; itr = itr->prev) {
			cout << *itr->data << " <-> ";
		}
		cout << endl;
	}
	void YoneticiListesi::printReverseOrder() {
		printNodesFromPositionInReverseOrder(size - 1);
	}
	int YoneticiListesi::UpdateNodePosition(YoneticiDugum* iter, double prevOrtalama, int index)
	{
		double yeniOrtalama = iter->data->ortalama;
		YoneticiDugum* tail = head;
		int counter = 0;
		while (tail->next != NULL)
		{
			tail = tail->next;
			counter++;
		}
		if (yeniOrtalama < head->data->ortalama)
		{
			if (iter->next != NULL)iter->next->prev = iter->prev;
			if (iter->prev != NULL)iter->prev->next = iter->next;
			iter->next = head;
			iter->prev = head->prev;
			head->prev = iter;
			head = iter;
			index = 0;
		}
		else if (yeniOrtalama > tail->data->ortalama)
		{
			if (iter->next != NULL)iter->next->prev = iter->prev;
			if (iter->prev != NULL)iter->prev->next = iter->next;
			iter->prev = tail;
			iter->next = tail->next;
			tail->next = iter;
			index = counter;
		}
		else
		{
			if (yeniOrtalama > prevOrtalama)
			{
				YoneticiDugum* temp = iter;
				while (temp->next != NULL && temp->next->data->ortalama < yeniOrtalama)
				{
					temp = temp->next;
					index++;
				}
				if (temp != iter)
				{
					if (iter->next != NULL)iter->next->prev = iter->prev;
					if (iter->prev != NULL)iter->prev->next = iter->next;
					else
						head = iter->next;
					iter->next = temp->next;
					iter->prev = temp;
					temp->next->prev = iter;
					temp->next = iter;
				}
			}
			else
			{
				YoneticiDugum* temp = iter;
				while (temp->prev != NULL && temp->prev->data->ortalama > yeniOrtalama)
				{
					temp = temp->prev;
					index--;
				}
				if (temp != iter)
				{
					if (iter->next != NULL)iter->next->prev = iter->prev;
					if (iter->prev != NULL)iter->prev->next = iter->next;
					iter->prev = temp->prev;
					iter->next = temp;
					temp->prev->next = iter;
					temp->prev = iter;
				}
			}
		}
		return index;
	}
	YoneticiListesi::~YoneticiListesi() {
		clear();
	}