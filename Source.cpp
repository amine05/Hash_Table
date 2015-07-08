# include<iostream>
# include<string>
# include<cctype>
# include<string.h>
# include<cstring>
using namespace std;

struct node
{
	char data[45];
	node *next;
};

node *hashtable[26];


void add_list(node *newItem,int key)
{
	if (hashtable[key]== NULL)
	{
		hashtable[key] = newItem;
		return;
	}
	node * p = hashtable[key];
	node * q = hashtable[key];
	while (q)
	{
		p = q;
		q = p->next;
	}
	p->next = newItem;
}

int Hash(char a[])
{
	return (int)(tolower(a[0])-'a');
}

void show()
{
	for (int i = 0; i < 26; i++)
	{
		node *temp = hashtable[i];
		while (temp != NULL)
		{
			cout << " # " << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}
}

int main()
{
	char data[45];
	node *temp=NULL;
	
	cout << "Please enter Data use 000 to exit " << endl;
	cin >> data;
	while(strcmp(data,"000") != 0)
	{
		temp = new node;
		strcpy_s(temp->data, data);
		temp->next = NULL;
		add_list(temp,Hash(temp->data));

		cout << "Please enter Data use 000 to exit " << endl;
		cin >> data;
	}
	show();
}