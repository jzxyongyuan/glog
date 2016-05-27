#include "glog/logging.h"

int main(int argc, char* argv[]) {
    FLAGS_log_dir = "./log";     // ������־�ļ�����Ŀ¼,���Ŀ¼�������Ѿ����ڵ�,������������־�ļ�.

    // GLog���ɵ��ļ�����ʽ��[�ļ���].[�������].[�û���].[log].[�ȼ�].[������ʱ����].[PID]
    // ����:test_glog.J2RT9QDBPIXKGEO.Administrator.log.INFO.20131205-112354.3108
    // ÿ������������Ҫִ��1��InitGoogleLogging(),���򲻲�����־�ļ�.
    // ����:ֻ��xxApp::InitInstance()�е���һ��InitGoogleLogging(),xxDlg�в��ص���Ҳ�����־�����ָ���ļ�.
    
    google::InitGoogleLogging("test_glog");// ������־�ļ����е�"�ļ���"�ֶ�.

    DLOG(INFO)<<"debug log info.";
    LOG(INFO) << "info log";   // ��¼һ��INFO�ȼ�����־"����InitInstance()"
    LOG(WARNING) << "warning log";
    LOG(ERROR)<< "error log";
    //����FATAL����ֱ�Ӱѳ���core���������������ջ��Ϣ
    //LOG(FATAL)<< "fatal log";
    
    //������־
    for (int i=0; i<20; i++) {
        LOG_IF(INFO, (i > 10))<<"print "<<i;
    }

    for (int i=0; i<100; i++) {
        LOG_EVERY_N(INFO, 10) << "test " << i;
    }


    google::ShutdownGoogleLogging();     // ֹͣGLog,��InitGoogleLogging()�ɶ�ʹ��.

    return 0;
}
