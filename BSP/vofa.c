#include "vofa.h"
#include "usartx.h"


//RawData����Э�� ����
void RawData_Test(void)		//  ֱ�ӵ���������ʹ�� �����Ƿ����
{
    u1_SendByte(0x40);
    u1_SendByte(0x41);
    u1_SendByte(0x42);
    u1_SendByte(0x43);
    u1_SendByte(0x0d);
    u1_SendByte(0x0a);
}

//FireWater����Э�� ����
float a=5,b=10,c=20;
void FireWater_Test(void)
{
    a+=100;
    b+=50;
    c+=10;
    //u1_printf("%.2f,%.2f,%.2f\n",a,b,c);
}


//ʹ��justfloat ����Э�� ����

/*
Ҫ����ʾ:
1. float��unsigned long������ͬ�����ݽṹ����
2. union������������ݴ������ͬ�������ռ�
*/
typedef union
{
    float fdata;
    unsigned long ldata;
} FloatLongType;


/*
��������fת��Ϊ4���ֽ����ݴ����byte[4]��
*/
void Float_to_Byte(float f,unsigned char byte[])
{
    FloatLongType fl;
    fl.fdata=f;
    byte[0]=(unsigned char)fl.ldata;
    byte[1]=(unsigned char)(fl.ldata>>8);
    byte[2]=(unsigned char)(fl.ldata>>16);
    byte[3]=(unsigned char)(fl.ldata>>24);
}

/*
��4���ֽ�����byte[4]ת��Ϊ�����������*f��
*/
void Byte_to_Float(float *f,unsigned char byte[])
{
    FloatLongType fl;
    fl.ldata=0;
    fl.ldata=byte[3];
    fl.ldata=(fl.ldata<<8)|byte[2];
    fl.ldata=(fl.ldata<<8)|byte[1];
    fl.ldata=(fl.ldata<<8)|byte[0];
    *f=fl.fdata;
}

void Test_FloatAndByte(void)	//�����������ֽ�����ת��ʾ��
{
	float a=1.0;			//���͵����� ����ͨ��
	
	u8 byte[4]={0};			//floatת��Ϊ4���ֽ�����
	
	Float_to_Byte(a,byte);
	//u1_printf("%f\r\n",a);
	u1_SendArray(byte,4);	//1ת��Ϊ4�ֽ����� ����  0x00 0x00 0x80 0x3F
	a=2;	//�ı�aֵ
	Byte_to_Float(&a,byte);		//��byte����ת��Ϊ����������
	u1_SendByte(a);			//a = 1.0
}

/*  ����֡��ʽ
typedef struct
{	
	u8 byte[4];		//floatת��Ϊ4���ֽ�����
	u8 tail[4];	//֡β
}Frame_TypeDef;
	byte ������ת��������	tail ֡β
u8 byte[4]={0};		//floatת��Ϊ4���ֽ�����
u8 tail[4]={0x00, 0x00, 0x80, 0x7f};	//֡β
*/



void JustFloat_Test(void)	//justfloat ����Э�����
{
    static float a=1,b=2;	//���͵����� ����ͨ��
	a++;
	b++;
	u8 byte[4]={0};		//floatת��Ϊ4���ֽ�����
	u8 tail[4]={0x00, 0x00, 0x80, 0x7f};	//֡β
	
	//����λ����������ͨ������
	Float_to_Byte(a,byte);
	//u1_printf("%f\r\n",a);
	u1_SendArray(byte,4);	//1ת��Ϊ4�ֽ����� ����  0x00 0x00 0x80 0x3F
	
	Float_to_Byte(b,byte);
	u1_SendArray(byte,4);	//2ת��Ϊ4�ֽ����� ����  0x00 0x00 0x00 0x40 
	
	//����֡β
	u1_SendArray(tail,4);	//֡βΪ 0x00 0x00 0x80 0x7f

}

// ��vofa��������  ��������  ����ͨ��  ���ӻ���ʾ  ֡β
void vofa_sendData(float a, float b, float c, float d, float e, float f, float g, float h, float j, float k, float l, float o, float p, float i)
{
    u8 byte[4] = {0};                      // floatת��Ϊ4���ֽ�����
    u8 tail[4] = {0x00, 0x00, 0x80, 0x7f}; // ֡β

    // ����λ����������ͨ������
    Float_to_Byte(a, byte);
    // u1_printf("%f\r\n",a);
    u1_SendArray(byte, 4); // 

    Float_to_Byte(b, byte);
    u1_SendArray(byte, 4); // 

    Float_to_Byte(c, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(d, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(e, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(f, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(g, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(h, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(j, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(k, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(l, byte);
    u1_SendArray(byte, 4);

	Float_to_Byte(o, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(p, byte);
    u1_SendArray(byte, 4);
	
	Float_to_Byte(i, byte);
    u1_SendArray(byte, 4);
	
    // ����֡β
    u1_SendArray(tail, 4); // ֡βΪ 0x00 0x00 0x80 0x7f
}

// ��vofa��������  1������  1��ͨ��  ���ӻ���ʾ  ֡β
void Vofa_sendData(float Byte)
{
    u8 byte[4] = {0};                      // floatת��Ϊ4���ֽ�����
    u8 tail[4] = {0x00, 0x00, 0x80, 0x7f}; // ֡β

    // ����λ����������ͨ������
    Float_to_Byte(Byte, byte);
    // u1_printf("%f\r\n",a);
    u1_SendArray(byte, 4); // 1ת��Ϊ4�ֽ����� ����  0x00 0x00 0x80 0x3F

    // ����֡β
    u1_SendArray(tail, 4); // ֡βΪ 0x00 0x00 0x80 0x7f
}

