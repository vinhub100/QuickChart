
#include <QCoreApplication>
#include "common.h"
#include "service.h"




//////////////////////////////
//extern "C" {

#include <linux/uinput.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//

int fd;

void send(int type, int code, int val)
{
   struct input_event ie;

   ie.type = static_cast<unsigned short>(type);
   ie.code = static_cast<unsigned short>(code);
   ie.value = val;
   /* timestamp values below are ignored */
   ie.time.tv_sec = 0;
   ie.time.tv_usec = 0;

   write(fd, &ie, sizeof(ie));
}

int initCtrlV(void)
{
   struct uinput_setup usetup;

   fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);


   ioctl(fd, UI_SET_EVBIT, EV_KEY);
   ioctl(fd, UI_SET_KEYBIT, KEY_LEFTCTRL);
   ioctl(fd, UI_SET_KEYBIT, KEY_V);

   // ioctl(fd, UI_SET_KEYBIT, 57); space = 57
   // ioctl(fd, UI_SET_KEYBIT, 29); left ctl = 29
   // ioctl(fd, UI_SET_KEYBIT, 47); char 'v' = 47

   memset(&usetup, 0, sizeof(usetup));
   usetup.id.bustype = BUS_USB;
   usetup.id.vendor = 0x1234; /* sample vendor */
   usetup.id.product = 0x5678; /* sample product */
   strcpy(usetup.name, "kanet Psudo Keyboard");

   ioctl(fd, UI_DEV_SETUP, &usetup);
   ioctl(fd, UI_DEV_CREATE);





   return 0;
}

int CtrlV(int msec){
    std::this_thread::sleep_for(std::chrono::milliseconds(msec));

    /* Key press, report the event, send key release, and report again */
    send(EV_KEY, KEY_LEFTCTRL, 1);
    send(EV_SYN, SYN_REPORT, 0);

    send(EV_KEY, KEY_V, 1);
    send(EV_SYN, SYN_REPORT, 0);

    send(EV_KEY, KEY_V, 0);
    send(EV_SYN, SYN_REPORT, 0);

    send(EV_KEY, KEY_LEFTCTRL, 0);
    send(EV_SYN, SYN_REPORT, 0);

    return 1;
}


int closeCtrlV(){
    ioctl(fd, UI_DEV_DESTROY);
    close(fd);
    return 1;
}

//}


//////////////////////////////



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
        Service service;
    return a.exec();
}
