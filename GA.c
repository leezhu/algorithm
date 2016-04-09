#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//���ݶ���
#define Cmax 100	//���ֵ
#define Cmin 0 

#define LENGHT1 3 //	Ⱦɫ�峤��
#define LENGHT2	3

#define CHROMLENGHT LENGHT1+LENGHT2
const int MaxGeneration = 100;//����������
const int PopSize = 10;//������С
const double Pc = 0.6;//�������
const double Pm = 0.001;//�������


//���ݶ���

struct Individual
{
	char chrom[CHROMLENGHT+1];
	double value;//Ŀ��ֵ
	double fitness;//��Ӧ��
};

int generation;//��������
int bestIndex;//��ø����±�
int worstIndex;//�

Individual bestIndividual;
Individual worstIndividual;

//��ǰ��á�
Individual currentBest;
Individual population[PopSize];


/////��������

void generateInitialPopulation();//��ʼ��
void generateNextPopulation();//������һ��
void evalutePopulation();//�����˿�
long decomdeChromosome(char *,int,int);//Ⱦɫ���֦
void calculateObjectValue();//�������ֵ
void calculateFitnessValue();//��Ӧ�Ⱥ���
void findBestAndWorstIndividual();
void performEvolution();//ִ�н���
void selectionOperator();//ѡ�����
void crossoverOperator();
void mutationOperator();
void outputTextReport();

///������

int main()
{
	generation = 0;
	generationInitialPopulation();
	evalutePopulation();

	while(generation<MaxGeneration)
	{
		generation++;
		generationNextPopulation();
		evalutePopulation();
		performEvolution();
		outputTextReport();
	}

	return 0;
}

///////
////��һ������,��ʼ��10������

void generateInitialPopulation()
{
	int i,j;
	srand((unsigned)time(NULL));

	for (i = 0;i<PopSize;i++)
	{
		for(j = 0;j<CHROMLENGH;j++)
			population[i].chrom[j] = ((rand()%10)<5)?'0':'1';
		population[i].chrom[CHROMLENGTH]='\0';//���һ����־λ
	}
}

//������һ������
void generateNextPopulation()
{
	selectionOperator();
	crossoverOperator();
	mutationOperator();
}
void evalutePopulation();//�����˿�
long decomdeChromosome(char *,int,int);//Ⱦɫ���֦
void calculateObjectValue();//�������ֵ
void calculateFitnessValue();//��Ӧ�Ⱥ���
void findBestAndWorstIndividual();
void performEvolution();//ִ�н���
void selectionOperator();//ѡ�����

//��������
void crossoverOperator()
{
	int i,j;
	int index[PopSize];
	int point,temp;
	double p;
	char ch;

	for (i = 0;i<PopSize;i++)
		index[i]=i;

	for (i = 0;i<PopSize;i++)	//ÿһ��ȫ�����ң�ʵ�ֽ���
	{
		point = rand()%(PopSize-i);
		temp = index[i];
		index[i] = index[point+i];
		index[point+i] = temp;
	}

	for (i = 0;i<PopSize-1;i+=2)
	{
		p = rand()%1000/1000.0;

		if(p<Pc)
		{
			point = rand()%(CHROMLENGTH-1)+1;//����ҳ�����㣬Ȼ��ʵ�����������Ľ���
			for (j = point;j<CHROMLENGTH;j++)
			{
				ch=population[index[i]].chrom[j];
				population[index[i]].chrom[j] = population[index[i]+1].chrom[j];
				population[index[i]+1].chrom[j] = ch;
			}
		}
	}
}

//��������
void mutationOperator()
{
	int i,j;
	double p;

	for (i =0;i<PopSize;i++)
	{
		for (j = 0;j<CHROMLENGTH;j++)
		{
			p = rand()%1000/1000.0;
			if (p <Pm)
				population[i].chrom[j]=(population[i].chrom[j]=='0')?'1':'0';//���С�����������ʾ͸ı�
		}
	}

}
void outputTextReport();


