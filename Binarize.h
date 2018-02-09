// Binarize.h 
//
// ��ֵ����Binarize��
// ����˵���������趨����ֵ���ԻҶ�ͼ����ж�ֵ���������õ���ֵͼ��
//
// �޶���ʷ��
//     ��ʼ�汾
//     ������ Out-Place �汾��ͼ���ֵ�������������˴����е�һЩ����
//     �����˴����е�һЩ����
//     �������°�ı���淶�Դ�������˵�������������һЩ֮ǰδ���ֵĸ�ʽ���� 

#ifndef __BINARIZE_H__
#define __BINARIZE_H__

#include "Image.h"
#include "ErrorCode.h"

// �ࣺBinarize
// �̳��ԣ���
// �����趨����ֵ���ԻҶ�ͼ����ж�ֵ���������õ���ֵͼ��������صĻҶ�ֵ��
// �ڵ�����ֵ�������صĻҶ�ֵ��ֵΪ 255��������صĻҶ�ֵС����ֵ�������صĻ�
// ��ֵ��ֵΪ 0��
class Binarize {

protected:

	// ��Ա������threshold(�Ҷ���ֵ)
	// ��ֵ���жϵı�׼����Χ�� [0, 255]��
	unsigned char threshold;

public:
	// ���캯����Binarize
	// �޲����汾�Ĺ��캯�������еĳ�Ա�����Գ�ʼ��ΪĬ��ֵ��
	__host__ __device__
		Binarize()
	{
		// ʹ��Ĭ��ֵΪ��ĸ�����Ա������ֵ��
		this->threshold = 128;  // �Ҷ���ֵĬ��Ϊ 128��
	}

	// ���캯����Binarize
	// �в����汾�Ĺ��캯����������Ҫ����������������Щ����ֵ�ڳ������й�����
	// ���ǿ��Ըı�ġ�
	__host__ __device__
		Binarize(
			unsigned char threshold  // �Ҷ���ֵ
		) {
		// ʹ��Ĭ��ֵΪ��ĸ�����Ա������ֵ����ֹ�û��ڹ��캯���Ĳ����и��˷Ƿ�
		// �ĳ�ʼֵ��ʹϵͳ����һ��δ֪��״̬��
		this->threshold = 128;  // �Ҷ���ֵĬ��Ϊ 128��

								// ���ݲ����б��е�ֵ�趨��Ա�����ĳ�ֵ
		setThreshold(threshold);
	}

	// ��Ա������getThreshold����ȡ�Ҷ���ֵ��
	// ��ȡ��Ա���� threshold ��ֵ��
	__host__ __device__ unsigned char  // ����ֵ����Ա���� threshold ��ֵ
		getThreshold() const
	{
		// ���� threshold ��Ա������ֵ��
		return this->threshold;
	}

	// ��Ա������setThreshold�����ûҶ���ֵ��
	// ���ó�Ա���� threshold ��ֵ��
	__host__ __device__ int          // ����ֵ�������Ƿ���ȷִ�У���������ȷִ
									 // �У����� NO_ERROR��
		setThreshold(
			unsigned char threshold  // �趨�µĻҶ���ֵ
		) {
		// �� threshold ��Ա����������ֵ
		this->threshold = threshold;

		return NO_ERROR;
	}

	// Host ��Ա������binarize����ֵ��������
	// ������ֵ��ͼ����ж�ֵ������������һ�� Out-Place ��ʽ�ġ�������صĻҶ�
	// ֵ���ڵ�����ֵ�������صĻҶ�ֵ��ֵΪ 255��������صĻҶ�ֵС����ֵ����
	// ���صĻҶ�ֵ��ֵΪ 0��
	__host__ int           // ����ֵ�������Ƿ���ȷִ�У���������ȷִ�У�����
						   // NO_ERROR��
		binarize(
			Image *inimg,  // ����ͼ��
			Image *outimg  // ���ͼ��
		);

	// Host ��Ա������binarize����ֵ��������
	// ������ֵ��ͼ����ж�ֵ������������һ�� In-Place ��ʽ�ġ�������صĻҶ�
	// ֵ���ڵ�����ֵ�������صĻҶ�ֵ��ֵΪ 255��������صĻҶ�ֵС����ֵ����
	// ���صĻҶ�ֵ��ֵΪ 0��
	__host__ int        // ����ֵ�������Ƿ���ȷִ�У���������ȷִ�У����� 
						// NO_ERROR��
		binarize(
			Image *img  // ����ͼ��
		);
};

#endif