#include "glog/logging.h"

int main(int argc, char* argv[]) {
    FLAGS_log_dir = "./log";     // 设置日志文件保存目录,这个目录必须是已经存在的,否则不能生成日志文件.

    // GLog生成的文件名格式是[文件名].[计算机名].[用户名].[log].[等级].[年月日时分秒].[PID]
    // 例如:test_glog.J2RT9QDBPIXKGEO.Administrator.log.INFO.20131205-112354.3108
    // 每个进程中至少要执行1次InitGoogleLogging(),否则不产生日志文件.
    // 例如:只在xxApp::InitInstance()中调用一次InitGoogleLogging(),xxDlg中不必调用也会把日志输出到指定文件.
    
    google::InitGoogleLogging("test_glog");// 设置日志文件名中的"文件名"字段.

    DLOG(INFO)<<"debug log info.";
    LOG(INFO) << "info log";   // 记录一个INFO等级的日志"我在InitInstance()"
    LOG(WARNING) << "warning log";
    LOG(ERROR)<< "error log";
    //慎用FATAL，或直接把程序core掉，保存程序运行栈信息
    //LOG(FATAL)<< "fatal log";
    
    //条件日志
    for (int i=0; i<20; i++) {
        LOG_IF(INFO, (i > 10))<<"print "<<i;
    }

    for (int i=0; i<100; i++) {
        LOG_EVERY_N(INFO, 10) << "test " << i;
    }


    google::ShutdownGoogleLogging();     // 停止GLog,与InitGoogleLogging()成对使用.

    return 0;
}
