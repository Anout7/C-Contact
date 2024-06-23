#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

void InitContact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
} 

void AddContact(Contact* pc) {
	assert(pc);
	if (pc->count == MAX) {
		printf("ͨѶ���������޷����\n");
		return;
	}

	printf("����������:>");
	scanf("%s", pc->data[pc->count].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->count].age));
 	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("������\n");
}

void ShowContact(const Contact* pc) {
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++) {
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}

}

static int FindByName(Contact* pc, char name[20]) {
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* pc) {
	assert(pc);
	int i = 0;

	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ�գ�û����Ϣ����ɾ��\n");
		return;
	}
	char name[20] = { 0 };
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("������\n");
		return;
	}
	for (i = pos; i < pc->count - 1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
};

void SearchContact(Contact* pc) {
	assert(pc);
	char name[20] = { 0 };
	printf("������Ҫ���ҵ�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else {
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);
	}
}

void ModifyContact(Contact* pc) {
	assert(pc);
	char name[20] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫ���ҵ��˲�����");
		return;
	}
	printf("��ʼ�޸�\n");
	printf("����������:>");
	scanf("%s", pc->data[pos].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pos].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pos].addr);

	printf("�޸����\n");
}

int cmp_peo_by_name(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc) {
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("�������\n");
}
