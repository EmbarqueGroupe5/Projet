#ifndef Magnetometer_h
#define Magnetometer_h

#include "Arduino.h"

#define BNO055_ADDRESS_B (0x29)
#define BNO055_ID        (0xA0)

class Magnetometer {
  public:
    //Address enums
    typedef enum
    {
      /* Page id register definition */
      BNO055_PAGE_ID_ADDR                                     = 0X07,
      
      /* PAGE0 REGISTER DEFINITION START*/
      BNO055_CHIP_ID_ADDR                                     = 0x00,

      /* Euler data registers */
      BNO055_EULER_H_LSB_ADDR                                 = 0X1A,
      BNO055_EULER_H_MSB_ADDR                                 = 0X1B,
      BNO055_EULER_R_LSB_ADDR                                 = 0X1C,
      BNO055_EULER_R_MSB_ADDR                                 = 0X1D,
      BNO055_EULER_P_LSB_ADDR                                 = 0X1E,
      BNO055_EULER_P_MSB_ADDR                                 = 0X1F,

      /* Status registers */
      BNO055_CALIB_STAT_ADDR                                  = 0X35,
      BNO055_SELFTEST_RESULT_ADDR                             = 0X36,
      BNO055_INTR_STAT_ADDR                                   = 0X37,

      /* Mode registers */
      BNO055_OPR_MODE_ADDR                                    = 0X3D,
      BNO055_PWR_MODE_ADDR                                    = 0X3E,

      BNO055_SYS_TRIGGER_ADDR                                 = 0X3F,

      BNO055_SYS_CLK_STAT_ADDR                                = 0X38,
      BNO055_SYS_STAT_ADDR                                    = 0X39,
      BNO055_SYS_ERR_ADDR                                     = 0X3A,

      /* Unit selection register */
      BNO055_UNIT_SEL_ADDR                                    = 0X3B,
      BNO055_DATA_SELECT_ADDR                                 = 0X3C
    } bno055_reg_t;

    typedef enum
    {
      POWER_MODE_NORMAL                                       = 0X00,
      POWER_MODE_LOWPOWER                                     = 0X01,
      POWER_MODE_SUSPEND                                      = 0X02
    } bno055_powermode_t;

    typedef enum
    {
      /* Operation mode settings*/
      OPERATION_MODE_CONFIG                                   = 0X00,
      OPERATION_MODE_ACCONLY                                  = 0X01,
      OPERATION_MODE_MAGONLY                                  = 0X02,
      OPERATION_MODE_GYRONLY                                  = 0X03,
      OPERATION_MODE_ACCMAG                                   = 0X04,
      OPERATION_MODE_ACCGYRO                                  = 0X05,
      OPERATION_MODE_MAGGYRO                                  = 0X06,
      OPERATION_MODE_AMG                                      = 0X07,
      OPERATION_MODE_IMUPLUS                                  = 0X08,
      OPERATION_MODE_COMPASS                                  = 0X09,
      OPERATION_MODE_M4G                                      = 0X0A,
      OPERATION_MODE_NDOF_FMC_OFF                             = 0X0B,
      OPERATION_MODE_NDOF                                     = 0X0C
    } bno055_opmode_t;


    typedef enum
    {
      VECTOR_EULER         = BNO055_EULER_H_LSB_ADDR
    } vector_type_t;

    //Magnetometer();
    bool  begin ();
    float getX();
    float getY();
    float getZ();

  private:
    byte  read8(bno055_reg_t reg);
    bool  readLen (bno055_reg_t, byte* buffer, uint8_t len);
    bool  write8  (bno055_reg_t, byte value);
    void  setMode (bno055_opmode_t mode);
    float* getValue();
    uint8_t _address = BNO055_ADDRESS_B;
};

#endif

