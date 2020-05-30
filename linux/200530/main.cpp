
#include <bits/stdc++.h>

using namespace std;

#define __PRINT_CUR_FUNCTION_NAME() cout<<__PRETTY_FUNCTION__<<endl;

#define SUCCESS true
#define FAILURE false

#define BMAP_MAX_SIZE 5

#define LOG_PRINT_SYSTEM_INFO() {\
	int i = 1, count = 0;\
	while(i){\
		count++;\
		i<<=1;\
	}\
	cout<<"systeminfo "<<count<<"bits"<<endl;\
	system("uname -a");\
}\

#define PRINT_ARRAY_DATA_INFO(ARRAY_NAME, ARRAY_SIZE_COL, ARRAY_SIZE_ROW) {\
	for(int i = 0; i < (ARRAY_SIZE_COL); ++i){\
		for(int j = 0; j < (ARRAY_SIZE_ROW); ++j){\
			cout<<"\t\t"<<(ARRAY_NAME)[i][j];\
		}\
		printf("\n");\
	}\
}\

#define PRINT_ARRAY_BIT_INFO(ARRAY_NAME, ARRAY_SIZE_COL, ARRAY_SIZE_ROW) {\
	for(int i = 0; i < (ARRAY_SIZE_COL); ++i){\
		for(int j = 0; j < (ARRAY_SIZE_ROW); ++j){\
			int tmp = 1;\
			while(tmp){\
				cout<<(((ARRAY_NAME)[i][j]) & tmp);\
				tmp <<= 1;\
			}\
			cout<<"\t";\
		}\
		cout<<endl;\
	}\
}\
				

struct DATA_COL_ROW_LOC
{
	unsigned int col;
	unsigned int row;
	uint32_t loc;
};

class bitmap
{
	private:
		int _bmap[BMAP_MAX_SIZE][BMAP_MAX_SIZE];

	public:
		bitmap()
		{
			__PRINT_CUR_FUNCTION_NAME();
			for(int i = 0; i < BMAP_MAX_SIZE; ++i)
			{
				for(int j = 0; j < BMAP_MAX_SIZE; ++j)
				{
					_bmap[i][j] = 0;
				}
			}
		}

		bool _bmap_print()
		{
			__PRINT_CUR_FUNCTION_NAME();
#ifdef SUCCESS
			PRINT_ARRAY_DATA_INFO(_bmap, BMAP_MAX_SIZE, BMAP_MAX_SIZE);
			LOG_PRINT_SYSTEM_INFO();
			return SUCCESS;
#else
			return FAILURE;
#endif
		}

		bool _bmap_print_bit()
		{
			__PRINT_CUR_FUNCTION_NAME();
			PRINT_ARRAY_BIT_INFO(_bmap, BMAP_MAX_SIZE, BMAP_MAX_SIZE);
			LOG_PRINT_SYSTEM_INFO();
			return SUCCESS;
		}

		bool _bmap_set(unsigned int col, unsigned int row, uint32_t location)
		{
			__PRINT_CUR_FUNCTION_NAME();
#ifdef SUCCESS
			_bmap[col][row] = (1 << location) | _bmap[col][row];
			return SUCCESS;
#else
			return FAILURE;
#endif
		}

		bool _bmap_get(unsigned int col, unsigned int row, uint32_t location)
		{
			__PRINT_CUR_FUNCTION_NAME();
			if((_bmap[col][row] << location) & 1 == 1)
			{
				return SUCCESS;
			}
			else
			{
				return FAILURE;
			}
		}

		bool _bmap_auto_set(unsigned int number)
		{
			struct DATA_COL_ROW_LOC dcrl = _bmap_calculate_data_location(number);
			cout<<dcrl.col<<" "<<dcrl.row<<" "<<dcrl.loc<<endl;
			while(_bmap_get(dcrl.col, dcrl.row, dcrl.loc))
			{
				//......
				if(dcrl.loc < 31)
				{
					dcrl.loc++;
				}
				else
				{
					if(dcrl.row < BMAP_MAX_SIZE - 1)
					{
						dcrl.row++;
						dcrl.loc = 0;
					}
					else
					{
						if(dcrl.col < BMAP_MAX_SIZE - 1)
						{
							dcrl.col++;
							dcrl.row = 0;
							dcrl.loc = 0;
						}
						else
						{
							exit(0);
						}
					}
				}
			}
			_bmap_set(dcrl.col, dcrl.row, dcrl.loc);
		}

		struct DATA_COL_ROW_LOC
			_bmap_calculate_data_location(unsigned int number)
			{
				struct DATA_COL_ROW_LOC dcrl;
				int index = number % (BMAP_MAX_SIZE * BMAP_MAX_SIZE);
				dcrl.col = (index - 1) / BMAP_MAX_SIZE;
				dcrl.row = (index - 1) % BMAP_MAX_SIZE;
				dcrl.loc = number % 32;
				return dcrl;
			}
};

int main()
{
	bitmap bm;
	bm._bmap_print();
	
	for(unsigned int i = 3; i < 100000000; i *= 3)
	{
		cout<<i<<" "<<bm._bmap_auto_set(i)<<endl;
	}
	bm._bmap_print();
	bm._bmap_print_bit();
	return 0;
}
