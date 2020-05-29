#include "./include/DeviceDriver.h"

const char * DeviceDriver::DISK_FILE_NAME = "disk_fs.img";

DeviceDriver::DeviceDriver() {
    fp = fopen(DISK_FILE_NAME, "rb+");
	if(Exists())
	{
		printf("DeviceDriver %s finished!\n", DISK_FILE_NAME);
		//sleep(1);
	}
}

DeviceDriver::~DeviceDriver() {
    if (fp) {
        fclose(fp);
    }
}

/* ��龵���ļ��Ƿ���� */
bool DeviceDriver::Exists() {
    return fp != NULL;
}

/* �򿪾����ļ� */
void DeviceDriver::Construct() {
    fp = fopen(DISK_FILE_NAME, "wb+");
    if (fp == NULL) {
        printf("�򿪻��½��ļ�%sʧ�ܣ�\n", DISK_FILE_NAME);
        exit(-1);
    }
}

/* ʵ��д���̺��� */
void DeviceDriver::write(const void* buffer, unsigned int size, int offset, unsigned int origin) {
    if (offset >= 0) {
        fseek(fp, offset, origin);
    }
    fwrite(buffer, size, 1, fp);
}

/* ʵ��д���̺��� */
void DeviceDriver::read(void* buffer, unsigned int size, int offset, unsigned int origin) {
    if (offset >= 0) {
        fseek(fp, offset, origin);
    }
    fread(buffer, size, 1, fp);
}
