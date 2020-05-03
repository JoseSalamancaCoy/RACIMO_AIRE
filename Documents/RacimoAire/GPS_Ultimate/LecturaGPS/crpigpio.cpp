#include "crpigpio.h"
#include <QDebug>
Crpigpio::Crpigpio(QObject *parent) : QObject(parent)
{
    if(gpioInitialise()<0)
    {
        qDebug()<< "No fue posible iniciar ";
    }


}



Crpigpio::~Crpigpio()
{
    gpioTerminate();

}

int Crpigpio::OpenSPI(unsigned chanel, unsigned baudios, unsigned Flags) //Habilitar pines para SPI
{
   HanleSPI= spiOpen(chanel,baudios,Flags );
   if(HanleSPI>0)return HanleSPI;
   if(HanleSPI<0 )qDebug() << GetErrorCode(HanleSPI);
    return HanleSPI;
}

int Crpigpio::ReadSPI(QByteArray &arr,uint8_t count)
{
   int ret= spiRead(HanleSPI,arr.data(),count);
   if(ret<0 )qDebug() << GetErrorCode(ret);
   return ret;
}

int Crpigpio::WriteSPI(QByteArray &arr)
{

    int ret= spiWrite(HanleSPI,arr.data(),arr.length());
    if(ret<0 )qDebug() << GetErrorCode(ret);
    return ret;

}
int Crpigpio::WriteAndReadSPI(char *tx,char *rx, uint8_t count)
{
    int ret= spiXfer(HanleSPI,tx,rx,count);
    if(ret<0 )qDebug() << GetErrorCode(ret);
    return ret;

}


int Crpigpio::OpenSerialgpio(unsigned gpio, unsigned baud_rate, unsigned packs_bits)
{
    int ret = gpioSerialReadOpen(gpio,baud_rate,packs_bits);
    if(ret<0 )qDebug() << GetErrorCode(ret);
    return ret;
}
int Crpigpio::ReadSerialgpioInverter(unsigned gpio, unsigned invert)
{
    int ret = gpioSerialReadInvert(gpio,invert);
    if(ret<0 )qDebug() << GetErrorCode(ret);
    return ret;
}
int Crpigpio::ReadSerialgpio(unsigned gpio,char *buf, size_t bufSize)
{
    int ret = gpioSerialRead(gpio, buf,bufSize);
    if(ret<0 )qDebug() << GetErrorCode(ret);
    return ret;
}
int Crpigpio::CloseSerialgpio(unsigned gpio)
{
    int ret = gpioSerialReadClose(gpio);
    if(ret<0 )qDebug() << GetErrorCode(ret);
    return ret;
}



int Crpigpio::PWM(unsigned gpio,unsigned dutycycle)
{
    int ret= gpioPWM(gpio,dutycycle);
    if(ret!=0)qDebug() << GetErrorCode(ret);
    return ret;

}
int Crpigpio::SetPWMfrequency(unsigned gpio, unsigned frequency)
{
    int ret= gpioSetPWMfrequency(gpio,frequency);
    if(ret<0)qDebug() << GetErrorCode(ret);
    return ret;
}


int Crpigpio::SetPinMode(unsigned chanel, unsigned mode)
{
    int ret=gpioSetMode(chanel,mode);
    if(ret<0)qDebug() << GetErrorCode(ret);
    return ret;
}

int Crpigpio::SetPullUpDown(unsigned chanel, unsigned mode)
{
    int ret=gpioSetPullUpDown(chanel,mode);
    if(ret<0)qDebug() << GetErrorCode(ret);
    return ret;
}



unsigned Crpigpio::ReadGpio(int8_t pin)
{
    int ret=gpioRead(pin);
    if(ret<0)qDebug() << GetErrorCode(ret);
    if(ret>0)return PI_ON;
    else return PI_OFF;


}

bool Crpigpio::WriteGpio(int8_t pin, unsigned val)
{
    int ret= gpioWrite(pin,val);

    if(ret<0)
    {
        qDebug() << GetErrorCode(ret);
        return false;
    }

    return true;

}

QString Crpigpio::GetErrorCode(int err)
{
    QString ret;
    switch (err)
    {
    case PI_INIT_FAILED: ret="gpioInitialise failed"; break;
    case PI_BAD_USER_GPIO:   ret= " GPIO not 0-31"; break;
    case PI_BAD_GPIO:   ret= "-3 // GPIO not 0-53"; break;
    case PI_BAD_MODE:   ret= "-4 // mode not 0-7"; break;
    case PI_BAD_LEVEL:   ret= "-5 // level not 0-1"; break;
    case PI_BAD_PUD:   ret= "-6 // pud not 0-2"; break;
    case PI_BAD_PULSEWIDTH:   ret= " pulsewidth not 0 or 500-2500"; break;
    case PI_BAD_DUTYCYCLE:   ret= " dutycycle outside set range"; break;
    case PI_BAD_TIMER:   ret= "-9 // timer not 0-9"; break;
    case PI_BAD_MS:   ret= "-10 // ms not 10-60000"; break;
    case PI_BAD_TIMETYPE:   ret= "-1 // timetype not 0-1"; break;
    case PI_BAD_SECONDS :   ret= "-2 // seconds < 0"; break;
    case PI_BAD_MICROS:   ret= "-13 // micros not 0-999999"; break;
    case PI_TIMER_FAILED:   ret= "-4 // gpioSetTimerFunc failed"; break;
    case PI_BAD_WDOG_TIMEOUT:   ret= "-5 // timeout not 0-60000"; break;
    case PI_NO_ALERT_FUNC:   ret= "-6 // DEPRECATED"; break;
    case PI_BAD_CLK_PERIPH:   ret= "-7 // clock peripheral not 0-1"; break;
    case PI_BAD_CLK_SOURCE:   ret= "-8 // DEPRECATED"; break;
    case PI_BAD_CLK_MICROS:   ret= "-9 // clock micros not 1, 2, 4, 5, 8, or 10"; break;
    case PI_BAD_BUF_MILLIS:   ret= "-0 // buf millis not 100-10000"; break;
    case PI_BAD_DUTYRANGE:   ret= "-1 // dutycycle range not 25-40000"; break;

    case PI_BAD_SIGNUM:   ret= "-22 // signum not 0-63"; break;
    case PI_BAD_PATHNAME:   ret= "-3 // can't open pathname"; break;
    case PI_NO_HANDLE :   ret= "-24 // no handle available"; break;
    case PI_BAD_HANDLE:   ret= "-25 // unknown handle"; break;
    case PI_BAD_IF_FLAGS:   ret= "-6 // ifFlags > 4"; break;
    case PI_BAD_CHANNEL :   ret= "-7 // DMA channel not 0-14"; break;

    case PI_BAD_SOCKET_PORT :   ret= "-8 // socket port not 1024-32000"; break;
    case PI_BAD_FIFO_COMMAND:   ret= "-9 // unrecognized fifo command"; break;
    case PI_BAD_SECO_CHANNEL:   ret= "-0 // DMA secondary channel not 0-6"; break;
    case PI_NOT_INITIALISED :   ret= "-1 // function called before gpioInitialise"; break;
    case PI_INITIALISED :   ret= "-2 // function called after gpioInitialise"; break;
    case PI_BAD_WAVE_MODE:   ret= "-3 // waveform mode not 0-3"; break;
    case PI_BAD_CFG_INTERNAL:   ret= "-4 // bad parameter in gpioCfgInternals call"; break;
    case PI_BAD_WAVE_BAUD:   ret= "-5 // baud rate not 50-250K(RX)/50-1M(TX)"; break;
    case PI_TOO_MANY_PULSES :   ret= "-6 // waveform has too many pulses"; break;
    case PI_TOO_MANY_CHARS:   ret= "-7 // waveform has too many chars"; break;
    case PI_NOT_SERIAL_GPIO :   ret= "-8 // no bit bang serial read on GPIO"; break;
    case PI_BAD_SERIAL_STRUC:   ret= "-9 // bad (null) serial structure parameter"; break;
    case PI_BAD_SERIAL_BUF:   ret= "-0 // bad (null) serial buf parameter"; break;
    case PI_NOT_PERMITTED:   ret= "-1 // GPIO operation not permitted"; break;
    case PI_SOME_PERMITTED:   ret= "-2 // one or more GPIO not permitted"; break;
    case PI_BAD_WVSC_COMMND :   ret= "-3 // bad WVSC subcommand"; break;
    case PI_BAD_WVSM_COMMND :   ret= "-4 // bad WVSM subcommand"; break;
    case PI_BAD_WVSP_COMMND :   ret= "-5 // bad WVSP subcommand"; break;
    case PI_BAD_PULSELEN:   ret= "-6 // trigger pulse length not 1-100"; break;
    case PI_BAD_SCRIPT:   ret= "-47 // invalid script"; break;
    case PI_BAD_SCRIPT_ID:   ret= "-8 // unknown script id"; break;
    case PI_BAD_SER_OFFSET:   ret= "-9 // add serial data offset > 30 minutes"; break;
    case PI_GPIO_IN_USE :   ret= "-0 // GPIO already in use"; break;
    case PI_BAD_SERIAL_COUNT:   ret= "-1 // must read at least a byte at a time"; break;
    case PI_BAD_PARAM_NUM:   ret= "-2 // script parameter id not 0-9"; break;
    case PI_DUP_TAG:   ret= "-53 // script has duplicate tag"; break;
    case PI_TOO_MANY_TAGS:   ret= "-4 // script has too many tags"; break;
    case PI_BAD_SCRIPT_CMD:   ret= "-5 // illegal script command"; break;
    case PI_BAD_VAR_NUM :   ret= "-6 // script variable id not 0-149"; break;
    case PI_NO_SCRIPT_ROOM:   ret= "-7 // no more room for scripts"; break;
    case PI_NO_MEMORY :   ret= "-58 // can't allocate temporary memory"; break;
    case PI_SOCK_READ_FAILED:   ret= "-9 // socket read failed"; break;
    case PI_SOCK_WRIT_FAILED:   ret= "-0 // socket write failed"; break;
    case PI_TOO_MANY_PARAM:   ret= "-1 // too many script parameters (> 10)"; break;
    case PI_NOT_HALTED:   ret= "-62 // DEPRECATED"; break;
    case PI_BAD_TAG:   ret= "-63 // script has unresolved tag"; break;
    case PI_BAD_MICS_DELAY:   ret= "-4 // bad MICS delay (too large)"; break;
    case PI_BAD_MILS_DELAY:   ret= "-5 // bad MILS delay (too large)"; break;
    case PI_BAD_WAVE_ID :   ret= "-6 // non existent wave id"; break;
    case PI_TOO_MANY_CBS:   ret= "-7 // No more CBs for waveform"; break;
    case PI_TOO_MANY_OOL:   ret= "-8 // No more OOL for waveform"; break;
    case PI_EMPTY_WAVEFORM:   ret= "-9 // attempt to create an empty waveform"; break;
    case PI_NO_WAVEFORM_ID:   ret= "-0 // no more waveforms"; break;
    case PI_I2C_OPEN_FAILED :   ret= "-1 // can't open I2C device"; break;
    case PI_SER_OPEN_FAILED :   ret= "-2 // can't open serial device"; break;
    case PI_SPI_OPEN_FAILED :   ret= "-3 // can't open SPI device"; break;
    case PI_BAD_I2C_BUS :   ret= "-4 // bad I2C bus"; break;
    case PI_BAD_I2C_ADDR:   ret= "-5 // bad I2C address"; break;
    case PI_BAD_SPI_CHANNEL :   ret= "-6 // bad SPI channel"; break;
    case PI_BAD_FLAGS :   ret= "-77 // bad i2c/spi/ser open flags"; break;
    case PI_BAD_SPI_SPEED:   ret= "-8 // bad SPI speed"; break;
    case PI_BAD_SER_DEVICE:   ret= "-9 // bad serial device name"; break;
    case PI_BAD_SER_SPEED:   ret= "-0 // bad serial baud rate"; break;
    case PI_BAD_PARAM :   ret= "-81 // bad i2c/spi/ser parameter"; break;
    case PI_I2C_WRITE_FAILED:   ret= "-2 // i2c write failed"; break;
    case PI_I2C_READ_FAILED :   ret= "-3 // i2c read failed"; break;
    case PI_BAD_SPI_COUNT:   ret= "-4 // bad SPI count"; break;
    case PI_SER_WRITE_FAILED:   ret= "-5 // ser write failed"; break;
    case PI_SER_READ_FAILED :   ret= "-6 // ser read failed"; break;
    case PI_SER_READ_NO_DATA:   ret= "-7 // ser read no data available"; break;
    case PI_UNKNOWN_COMMAND :   ret= "-8 // unknown command"; break;
    case PI_SPI_XFER_FAILED :   ret= "-9 // spi xfer/read/write failed"; break;
    case PI_BAD_POINTER :   ret= "-0 // bad (NULL) pointer"; break;
    case PI_NO_AUX_SPI:   ret= "-91 // no auxiliary SPI on Pi A or B"; break;
    case PI_NOT_PWM_GPIO:   ret= "-2 // GPIO is not in use for PWM"; break;
    case PI_NOT_SERVO_GPIO:   ret= "-3 // GPIO is not in use for servo pulses"; break;
    case PI_NOT_HCLK_GPIO:   ret= "-4 // GPIO has no hardware clock"; break;
    case PI_NOT_HPWM_GPIO:   ret= "-5 // GPIO has no hardware PWM"; break;
    case PI_BAD_HPWM_FREQ:   ret= "-6 // hardware PWM frequency not 1-125M"; break;
    case PI_BAD_HPWM_DUTY:   ret= "-7 // hardware PWM dutycycle not 0-1M"; break;
    case PI_BAD_HCLK_FREQ:   ret= "-8 // hardware clock frequency not 4689-250M"; break;
    case PI_BAD_HCLK_PASS:   ret= "-9 // need password to use hardware clock 1"; break;
    case PI_HPWM_ILLEGAL:   ret= "-00 // illegal, PWM in use for main clock"; break;
    case PI_BAD_DATABITS:   ret= "-01 // serial data bits not 1-32"; break;
    case PI_BAD_STOPBITS:   ret= "-02 // serial (half) stop bits not 2-8"; break;
    case PI_MSG_TOOBIG :   ret= "-03 // socket/pipe message too big"; break;
    case PI_BAD_MALLOC_MODE:   ret= "-04 // bad memory allocation mode"; break;
    case PI_TOO_MANY_SEGS:   ret= "-05 // too many I2C transaction segments"; break;
    case PI_BAD_I2C_SEG:   ret= "-06 // an I2C transaction segment failed"; break;
    case PI_BAD_SMBUS_CMD:   ret= "-07 // SMBus command not supported by driver"; break;
    case PI_NOT_I2C_GPIO:   ret= "-08 // no bit bang I2C in progress on GPIO"; break;
    case PI_BAD_I2C_WLEN:   ret= "-09 // bad I2C write length"; break;
    case PI_BAD_I2C_RLEN:   ret= "-10 // bad I2C read length"; break;
    case PI_BAD_I2C_CMD:   ret= "-11 // bad I2C command"; break;
    case PI_BAD_I2C_BAUD:   ret= "-12 // bad I2C baud rate, not 50-500k"; break;
    case PI_CHAIN_LOOP_CNT :   ret= "-13 // bad chain loop count"; break;
    case PI_BAD_CHAIN_LOOP :   ret= "-14 // empty chain loop"; break;
    case PI_CHAIN_COUNTER:   ret= "-15 // too many chain counters"; break;
    case PI_BAD_CHAIN_CMD:   ret= "-16 // bad chain command"; break;
    case PI_BAD_CHAIN_DELAY:   ret= "-17 // bad chain delay micros"; break;
    case PI_CHAIN_NESTING:   ret= "-18 // chain counters nested too deeply"; break;
    case PI_CHAIN_TOO_BIG:   ret= "-19 // chain is too long"; break;
    case PI_DEPRECATED :   ret= "-20 // deprecated function removed"; break;
    case PI_BAD_SER_INVERT :   ret= "-21 // bit bang serial invert not 0 or 1"; break;
    case PI_BAD_EDGE :   ret= "-122 // bad ISR edge value, not 0-2"; break;
    case PI_BAD_ISR_INIT:   ret= "-23 // bad ISR initialisation"; break;
    case PI_BAD_FOREVER:   ret= "-24 // loop forever must be last command"; break;
    case PI_BAD_FILTER :   ret= "-25 // bad filter parameter"; break;
    case PI_BAD_PAD:   ret= "-126 // bad pad number"; break;
    case PI_BAD_STRENGTH:   ret= "-27 // bad pad drive strength"; break;
    case PI_FIL_OPEN_FAILED:   ret= "-28 // file open failed"; break;
    case PI_BAD_FILE_MODE:   ret= "-29 // bad file mode"; break;
    case PI_BAD_FILE_FLAG:   ret= "-30 // bad file flag"; break;
    case PI_BAD_FILE_READ:   ret= "-31 // bad file read"; break;
    case PI_BAD_FILE_WRITE :   ret= "-32 // bad file write"; break;
    case PI_FILE_NOT_ROPEN :   ret= "-33 // file not open for read"; break;
    case PI_FILE_NOT_WOPEN :   ret= "-34 // file not open for write"; break;
    case PI_BAD_FILE_SEEK:   ret= "-35 // bad file seek"; break;
    case PI_NO_FILE_MATCH:   ret= "-36 // no files match pattern"; break;
    case PI_NO_FILE_ACCESS :   ret= "-37 // no permission to access file"; break;
    case PI_FILE_IS_A_DIR:   ret= "-38 // file is a directory"; break;
    case PI_BAD_SHELL_STATUS:   ret= "-39 // bad shell return status"; break;
    case PI_BAD_SCRIPT_NAME:   ret= "-40 // bad script name"; break;
    case PI_BAD_SPI_BAUD:   ret= "-41 // bad SPI baud rate, not 50-500k"; break;
    case PI_NOT_SPI_GPIO:   ret= "-42 // no bit bang SPI in progress on GPIO"; break;
    case PI_BAD_EVENT_ID:   ret= "-43 // bad event id"; break;
    default: ret="No defined error"; break;

    };

    return ret;
}

void Crpigpio::SetISRgpio(unsigned gpio, unsigned level, uint32_t tick)
{
    gpioSetISRFuncEx(gpio,level,tick,reciveISR,this);
}

void Crpigpio::reciveISR(int gpio, int level, uint32_t tick,void *usr)
{
    Crpigpio * pTevent= (Crpigpio *)usr;
    pTevent->SendISR(gpio,level,tick);
}

void Crpigpio::SendISR(int gpio,int level,quint32 tick)
{
    emit OnCallBackISR(gpio,level,tick);

}
