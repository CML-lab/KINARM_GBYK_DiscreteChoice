/*
 * Code generation for system system '<S34>/createKINData'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_createKINData.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Forward declaration for local functions */
static void gbyk_v4b_correct_elbow_angle(real_T elbow_angle, real_T elbow_vel,
  real_T elbow_acc, real_T theta2_5, real_T L1, real_T L5, real_T L3_error,
  real_T *angle_corr, real_T *vel_corr, real_T *acc_corr);
static void gbyk_v4b_create_robot_row(const real_T calibration[8], const real_T
  hardware_settings[12], const real_T force_sensor_data[7], const real_T
  robot_data[10], const real_T torque_command[2], real_T robot_row[50]);
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S70>/Create KINARM Data Array' */
static void gbyk_v4b_correct_elbow_angle(real_T elbow_angle, real_T elbow_vel,
  real_T elbow_acc, real_T theta2_5, real_T L1, real_T L5, real_T L3_error,
  real_T *angle_corr, real_T *vel_corr, real_T *acc_corr)
{
  real_T L3;
  real_T theta1_3;
  real_T a;
  real_T b;
  real_T dbdt;
  real_T dcdt;
  real_T d2bdt2;
  real_T d2cdt2;
  real_T sinU;
  real_T dsinUdt;

  /*  The timestamp from the force sensor(s) */
  /*  this function corrects for errors in non-perfect parallelogram structure */
  /*  It assumes that L5 is exact (because it is machined from one */
  /*  piece of material) and that there is an error in L3.  Note: although */
  /*  there could also be an error in L4, this 'correction' factor can */
  /*  effectively account for both errors by computing an equivalent L3_error */
  /* '<S236>:1:404' */
  L3 = L5 + L3_error;

  /* '<S236>:1:406' */
  theta1_3 = theta2_5 - elbow_angle;

  /* actual angle between links 1 and 3 */
  /* '<S236>:1:407' */
  /* '<S236>:1:408' */
  /*  The following shifts theta1_3 to between -pi and pi and stores the shift. */
  /*  Although theta1_3 should always be between 0 and pi, during initial */
  /*  calibration there might be some values outside of that range. */
  /* '<S236>:1:413' */
  /* '<S236>:1:414' */
  theta1_3 -= floor((theta1_3 + 3.1415926535897931) / 6.2831853071795862) * 2.0 *
    3.1415926535897931;

  /* Option 1a */
  /* '<S236>:1:417' */
  a = 4.0 * L3 * L5 - 4.0 * L1 * L5 * cos(theta1_3);

  /* '<S236>:1:418' */
  b = -4.0 * L1 * L5 * sin(theta1_3);

  /* '<S236>:1:419' */
  /* '<S236>:1:421' */
  dbdt = -4.0 * L1 * L5 * cos(theta1_3) * -elbow_vel;

  /* '<S236>:1:422' */
  dcdt = 2.0 * L1 * L3_error * sin(theta1_3) * -elbow_vel;

  /* '<S236>:1:424' */
  d2bdt2 = 4.0 * L1 * L5 * sin(theta1_3) * (-elbow_vel * -elbow_vel) - 4.0 * L1 *
    L5 * cos(theta1_3) * -elbow_acc;

  /* '<S236>:1:425' */
  d2cdt2 = 2.0 * L1 * L3_error * cos(theta1_3) * (-elbow_vel * -elbow_vel) + 2.0
    * L1 * L3_error * sin(theta1_3) * -elbow_acc;

  /* '<S236>:1:427' */
  theta1_3 = sqrt(b * b - (((L3 * L3 + L5 * L5) - 2.0 * L3 * L5) - 2.0 * L1 *
    L3_error * cos(theta1_3)) * (4.0 * a));
  if (theta1_3 > 0.0) {
    /* '<S236>:1:429' */
    if (b > 0.0) {
      /* '<S236>:1:430' */
      /* '<S236>:1:431' */
      sinU = (-b + theta1_3) / (2.0 * a);

      /* '<S236>:1:432' */
      dsinUdt = ((2.0 * b * dbdt - 4.0 * a * dcdt) * (0.5 / theta1_3) + -dbdt) /
        (2.0 * a);

      /* '<S236>:1:433' */
      L3 = 2.0 * b * dbdt - 4.0 * a * dcdt;
      L3 = (((dbdt * dbdt * 2.0 + 2.0 * b * d2bdt2) - 4.0 * a * d2cdt2) * (0.5 /
             theta1_3) + (-d2bdt2 - 0.25 / rt_powd_snf(theta1_3, 3.0) * (L3 * L3)))
        / (2.0 * a);
    } else {
      /* '<S236>:1:435' */
      sinU = (-b - theta1_3) / (2.0 * a);

      /* '<S236>:1:436' */
      dsinUdt = (-dbdt - (2.0 * b * dbdt - 4.0 * a * dcdt) * (0.5 / theta1_3)) /
        (2.0 * a);

      /* '<S236>:1:437' */
      L3 = 2.0 * b * dbdt - 4.0 * a * dcdt;
      L3 = ((0.25 / rt_powd_snf(theta1_3, 3.0) * (L3 * L3) + -d2bdt2) - ((dbdt *
              dbdt * 2.0 + 2.0 * b * d2bdt2) - 4.0 * a * d2cdt2) * (0.5 /
             theta1_3)) / (2.0 * a);
    }
  } else {
    /* '<S236>:1:440' */
    sinU = -b / (2.0 * a);

    /* '<S236>:1:441' */
    dsinUdt = -dbdt / (2.0 * a);

    /* '<S236>:1:442' */
    L3 = -d2bdt2 / (2.0 * a);
  }

  if (sinU > 1.0) {
    /* '<S236>:1:445' */
    /* '<S236>:1:446' */
    sinU = 1.0;
  } else {
    if (sinU < -1.0) {
      /* '<S236>:1:447' */
      /* '<S236>:1:448' */
      sinU = -1.0;
    }
  }

  /* '<S236>:1:451' */
  /* '<S236>:1:453' */
  /* '<S236>:1:454' */
  /* '<S236>:1:455' */
  /* '<S236>:1:457' */
  *angle_corr = -(2.0 * asin(sinU));

  /* '<S236>:1:458' */
  *vel_corr = -(2.0 / sqrt(1.0 - sinU * sinU) * dsinUdt);

  /* '<S236>:1:459' */
  *acc_corr = -(2.0 / rt_powd_snf(1.0 - sinU * sinU, 1.5) * sinU * (dsinUdt *
    dsinUdt) + 2.0 / sqrt(1.0 - sinU * sinU) * L3);
}

/* Function for MATLAB Function: '<S70>/Create KINARM Data Array' */
static void gbyk_v4b_create_robot_row(const real_T calibration[8], const real_T
  hardware_settings[12], const real_T force_sensor_data[7], const real_T
  robot_data[10], const real_T torque_command[2], real_T robot_row[50])
{
  boolean_T isEP;
  real_T force_sensor_force_u;
  real_T force_sensor_force_v;
  real_T force_sensor_force_w;
  real_T force_sensor_torque_u;
  real_T force_sensor_torque_v;
  real_T force_sensor_torque_w;
  real_T elbow_velocity;
  real_T elbow_acceleration;
  real_T shoulder_angle;
  real_T elbow_angle;
  int32_T arm_orientation;
  real_T L1_angle;
  real_T L2_angle;
  real_T pointer_angle;
  real_T L1_velocity;
  real_T L2_velocity;
  real_T L1_acceleration;
  real_T L2_acceleration;
  real_T M1_torque_cmd;
  real_T M2_torque_cmd;
  real_T elbow_position_x;
  real_T elbow_position_y;
  real_T elbow_velocity_x;
  real_T elbow_velocity_y;
  real_T elbow_acceleration_x;
  real_T elbow_acceleration_y;
  real_T sensor_u_angle;
  real_T force_sensor_force_x;
  real_T force_sensor_force_y;
  real_T force_sensor_force_z;
  real_T force_sensor_torque_x;
  real_T force_sensor_torque_y;
  real_T force_sensor_torque_z;
  boolean_T b;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  This function creates a row of arm-specific data for the KINARM data matrix.  */
  /*  Extract the relevant information from each input array. */
  /* '<S236>:1:156' */
  /*  offset added to motion control card shoulder angle to get real angle (rad) */
  /* '<S236>:1:157' */
  /*  offset added to motion control card elbow angle to get real angle (rad) */
  /* '<S236>:1:158' */
  /*  shoulder x position (m) (global coordinates) */
  /* '<S236>:1:159' */
  /*  shoulder y position (m) (global coordinates) */
  /* '<S236>:1:160' */
  /*  L1 (upper arm segment) length (m) */
  /* '<S236>:1:161' */
  /*  L2 (forearm segment) length (m); segment length puts distal end in line with subject pointer */
  /* '<S236>:1:162' */
  /*  perpendicular distance from L2 to subject pointer (m) */
  /* '<S236>:1:163' */
  /*  L3 error, the difference between lengths L3 and L5 (m) */
  /* '<S236>:1:165' */
  /*  robot type (0: EXO, 1: EP, 2:NHP) */
  if ((hardware_settings[0] == 0.0) || (hardware_settings[0] == 2.0)) {
    /* '<S236>:1:166' */
    b = true;
  } else {
    /* '<S236>:1:166' */
    b = false;
  }

  /* '<S236>:1:167' */
  isEP = (hardware_settings[0] == 1.0);

  /* '<S236>:1:168' */
  /*  L5 segment length (m) */
  /* '<S236>:1:169' */
  /*  angle of L2 relative to L5 (rad) */
  /* '<S236>:1:170' */
  /*  offset of force sensor from forearm linkage (rad) */
  /* '<S236>:1:171' */
  /*  robot orientation (1: right-handed from robot perspective, -1: left-handed from robot perspective) */
  /* '<S236>:1:173' */
  /*  force sensor u force (N) */
  /* '<S236>:1:174' */
  /*  force sensor v force (N) */
  /* '<S236>:1:175' */
  /*  force sensor w force (N) */
  /* '<S236>:1:176' */
  /*  force sensor u torque (Nm)  */
  /* '<S236>:1:177' */
  /*  force sensor v torque (Nm) */
  /* '<S236>:1:178' */
  /*  force sensor w torque (Nm) */
  /* '<S236>:1:179' */
  /*  force sensor w torque (Nm) */
  /* '<S236>:1:181' */
  /*  current shoulder joint angle (rad) */
  /* '<S236>:1:182' */
  /*  current elbow joint angle (rad) */
  /* '<S236>:1:183' */
  /*  shoulder joint angular velocity (rad/s) */
  /* '<S236>:1:184' */
  elbow_velocity = robot_data[3];

  /*  elbow joint angular velocity (rad/s) */
  /* '<S236>:1:185' */
  /*  shoulder joint angular acceleration (rad/s^2) */
  /* '<S236>:1:186' */
  elbow_acceleration = robot_data[5];

  /*  elbow joint angular acceleration (rad/s^2) */
  /* '<S236>:1:187' */
  /*  filtered shoulder velocity (rad/s) */
  /* '<S236>:1:188' */
  /*  filtered elbow velocity (rad/s) */
  /* '<S236>:1:189' */
  /*  motor 1 status */
  /* '<S236>:1:190' */
  /*  motor 2 status */
  /* '<S236>:1:192' */
  /*  commanded shoulder torque (Nm) */
  /* '<S236>:1:193' */
  /*  commanded elbow torque (Nm) */
  /*  With the inputs unpacked, start using them to compute other values that will be included in the data array. Some inputs are included in the */
  /*  array directly, but the kinematic data is also developed from the joint-based information supplied by the polling function into information  */
  /*  about the arm segments, the elbow, and the hand/fingertip as described in the following sections. */
  /*  Before proceeding, the shoulder and elbow angles are shifted by the offsets determined by the calibration. If the calibration has been */
  /*  performed correctly, this ensures that the angle of 0 corresponds to when the arm is aligned with the coronal plane. In the case of the  */
  /*  elbow angle for a KINARM EXO, an extra correction is performed (using a utility function, and according to the current calibration) to  */
  /*  account for small imperfections in the parallelogram of KINARM links caused by differences in the lengths of L3 and L5 (which are  */
  /*  theoretically equal). */
  /* '<S236>:1:206' */
  shoulder_angle = robot_data[0] + calibration[0];

  /*  If the robot is an Exoskeleton, use the correct_elbow_angle function to account for imperfections on the KINARM robot parallelogram structure */
  if (b) {
    /* '<S236>:1:166' */
    gbyk_v4b_correct_elbow_angle(robot_data[1] + calibration[1], robot_data[3],
      robot_data[5], hardware_settings[3], calibration[4], hardware_settings[2],
      calibration[7], &force_sensor_torque_y, &force_sensor_torque_z,
      &sensor_u_angle);

    /* '<S236>:1:211' */
    elbow_angle = (robot_data[1] + calibration[1]) + force_sensor_torque_y;

    /* '<S236>:1:212' */
    elbow_velocity = robot_data[3] + force_sensor_torque_z;

    /* '<S236>:1:213' */
    elbow_acceleration = robot_data[5] + sensor_u_angle;
  } else {
    /* '<S236>:1:215' */
    elbow_angle = robot_data[1] + calibration[1];
  }

  /*  Convert robot orientation as supplied in the hardware settings (a scaling factor used to calculate robot data) to the number 1 or 2, */
  /*  indicating which of the subject's arms will normally be using the robot: right or left, respectively. This is done to be consistent  */
  /*  with previous versions of the TDK. Note that the robot orientations of KINARM EP robots are "opposite" those for KINARM EXOs when. */
  if ((isEP && (hardware_settings[5] < 0.0)) || (b && (hardware_settings[5] >
        0.0))) {
    /* '<S236>:1:221' */
    /* '<S236>:1:166' */
    /* '<S236>:1:221' */
    /* '<S236>:1:222' */
    arm_orientation = 1;

    /*  right arm orientation expected for subject */
  } else {
    /* '<S236>:1:224' */
    arm_orientation = 2;

    /*  left arm orientation expected for subject */
  }

  /*  Create a motor status variable for the robot that is consistent with previous versions of the TDK: the value forms a bitfield in */
  /*  which non-zero bits indicate a motor is disabled or faulted. The least significant bit is motor 1; the next is motor 2. */
  /* '<S236>:1:229' */
  /*  Calculate segment information, i.e. positions, velocities, and accelerations for L1 and L2. "Segment-based" values here differ from the */
  /*  "joint-based" values in a few ways, though they are still expressed in angles: */
  /*    i) elbow angles are no longer shoulder-relative (that is, L2 angles are not relative to L1) */
  /*   ii) positions are expressed with the corrections calculated above */
  /*  iii) all angles are expressed in the same system, where 0 is the angular position of the exoskeleton right arm when aligned with the  */
  /*       coronal plane and positive changes in angle correspond to counterclockwise movements. */
  /*  */
  /*  This section also determines the torque commands for motor 1 (shoulder) and motor 2 (elbow). When a positive torque is applied to the  */
  /*  forearm linkage by motor 2 it causes the same positive force on the upper arm linkage, so the torque applied to motor 1 is the desired */
  /*  shoulder torque less any torque commanded at the elbow. */
  /* '<S236>:1:242' */
  L1_angle = shoulder_angle;

  /* '<S236>:1:243' */
  L2_angle = shoulder_angle + elbow_angle;

  /* '<S236>:1:245' */
  pointer_angle = (shoulder_angle + elbow_angle) + 1.5707963267948966;

  /* '<S236>:1:247' */
  L1_velocity = robot_data[2];

  /* '<S236>:1:248' */
  L2_velocity = robot_data[2] + elbow_velocity;

  /* '<S236>:1:250' */
  L1_acceleration = robot_data[4];

  /* '<S236>:1:251' */
  L2_acceleration = robot_data[4] + elbow_acceleration;

  /* '<S236>:1:253' */
  M1_torque_cmd = torque_command[0] - torque_command[1];

  /* '<S236>:1:254' */
  M2_torque_cmd = torque_command[1];

  /*  a robot_orientation < 0 means that the robot is left-handed from its perspective (i.e. if you look at the robot structure,  */
  /*  and pretend that it is a humanoid, the robot itself looks left-handed).  For an Exoskeleton robot, this is the */
  /*  robot that the left-hand of the subject grabs. For an EP robot, this is the robot that the subjec'ts right-hand grabs.   */
  if (hardware_settings[5] == -1.0) {
    /* '<S236>:1:260' */
    /* '<S236>:1:261' */
    L1_angle = -shoulder_angle + 3.1415926535897931;

    /* '<S236>:1:262' */
    L2_angle = -L2_angle + 3.1415926535897931;

    /* '<S236>:1:264' */
    pointer_angle = -pointer_angle + 3.1415926535897931;

    /* '<S236>:1:266' */
    L1_velocity = -robot_data[2];

    /* '<S236>:1:267' */
    L2_velocity = -L2_velocity;

    /* '<S236>:1:269' */
    L1_acceleration = -robot_data[4];

    /* '<S236>:1:270' */
    L2_acceleration = -L2_acceleration;

    /* '<S236>:1:272' */
    M1_torque_cmd = -M1_torque_cmd;

    /* '<S236>:1:273' */
    M2_torque_cmd = -torque_command[1];
  }

  /*  Calculate elbow information, i.e. position, velocity, and acceleration, in X-Y space rather than joint angles. */
  /* '<S236>:1:277' */
  elbow_position_x = calibration[4] * cos(L1_angle) + calibration[2];

  /* '<S236>:1:278' */
  elbow_position_y = calibration[4] * sin(L1_angle) + calibration[3];

  /* '<S236>:1:280' */
  elbow_velocity_x = -calibration[4] * sin(L1_angle) * L1_velocity;

  /* '<S236>:1:281' */
  elbow_velocity_y = calibration[4] * cos(L1_angle) * L1_velocity;

  /* '<S236>:1:283' */
  elbow_acceleration_x = (L1_velocity * L1_velocity * cos(L1_angle) + sin
    (L1_angle) * L1_acceleration) * -calibration[4];

  /* '<S236>:1:284' */
  elbow_acceleration_y = (L1_velocity * L1_velocity * -sin(L1_angle) + cos
    (L1_angle) * L1_acceleration) * calibration[4];

  /*  Calculate fingertip/subject pointer/hand feedback information, i.e. position, velocity, and acceleration, in X-Y space. */
  /* '<S236>:1:287' */
  /* '<S236>:1:288' */
  /* '<S236>:1:290' */
  /* '<S236>:1:291' */
  /* '<S236>:1:293' */
  /* '<S236>:1:295' */
  /*  Calculate force sensor data for EP robots, or zero it for EXO robots. On each EP robot the force sensor is mounted at known angle to  */
  /*  the forearm linkage, which is specified as an input to this block. Two variants of the data are calculated: i) scaled in the force  */
  /*  sensor's local coordinate system ("uvw"), and ii) transformed to be in the global coordinate system ("xyz"). */
  if (isEP) {
    /* '<S236>:1:301' */
    /* '<S236>:1:303' */
    force_sensor_force_u = force_sensor_data[0] / 1.0E+6;

    /*  scale values to SI using factors defined in force sensor configurations */
    /* '<S236>:1:304' */
    force_sensor_force_v = force_sensor_data[1] / 1.0E+6;

    /* '<S236>:1:305' */
    force_sensor_force_w = force_sensor_data[2] / 1.0E+6;

    /* '<S236>:1:307' */
    force_sensor_torque_u = force_sensor_data[3] / 1.0E+6;

    /* '<S236>:1:308' */
    force_sensor_torque_v = force_sensor_data[4] / 1.0E+6;

    /* '<S236>:1:309' */
    force_sensor_torque_w = force_sensor_data[5] / 1.0E+6;

    /* '<S236>:1:311' */
    sensor_u_angle = L2_angle - hardware_settings[4];

    /* '<S236>:1:312' */
    force_sensor_torque_y = (L2_angle - hardware_settings[4]) -
      1.5707963267948966;

    /* '<S236>:1:314' */
    force_sensor_force_x = force_sensor_force_u * cos(sensor_u_angle) +
      force_sensor_force_v * cos(force_sensor_torque_y);

    /* '<S236>:1:315' */
    force_sensor_force_y = force_sensor_force_u * sin(sensor_u_angle) +
      force_sensor_force_v * sin(force_sensor_torque_y);

    /* '<S236>:1:316' */
    force_sensor_force_z = -force_sensor_force_w;

    /* '<S236>:1:318' */
    force_sensor_torque_x = force_sensor_torque_u * cos(sensor_u_angle) +
      force_sensor_torque_v * cos(force_sensor_torque_y);

    /* '<S236>:1:319' */
    force_sensor_torque_y = force_sensor_torque_u * sin(sensor_u_angle) +
      force_sensor_torque_v * sin(force_sensor_torque_y);

    /* '<S236>:1:320' */
    force_sensor_torque_z = -force_sensor_torque_w;
  } else {
    /* '<S236>:1:323' */
    force_sensor_force_u = 0.0;

    /* '<S236>:1:324' */
    force_sensor_force_v = 0.0;

    /* '<S236>:1:325' */
    force_sensor_force_w = 0.0;

    /* '<S236>:1:327' */
    force_sensor_torque_u = 0.0;

    /* '<S236>:1:328' */
    force_sensor_torque_v = 0.0;

    /* '<S236>:1:329' */
    force_sensor_torque_w = 0.0;

    /* '<S236>:1:331' */
    force_sensor_force_x = 0.0;

    /* '<S236>:1:332' */
    force_sensor_force_y = 0.0;

    /* '<S236>:1:333' */
    force_sensor_force_z = 0.0;

    /* '<S236>:1:335' */
    force_sensor_torque_x = 0.0;

    /* '<S236>:1:336' */
    force_sensor_torque_y = 0.0;

    /* '<S236>:1:337' */
    force_sensor_torque_z = 0.0;
  }

  /*  Construct the arm data array. Its construction is laid out here explicitly to provide comments for each entry (some are repeats from above).  */
  /* '<S236>:1:341' */
  /* '<S236>:1:343' */
  robot_row[0] = calibration[4];

  /*  L1 (upper arm segment) length (m) */
  /* '<S236>:1:344' */
  robot_row[1] = calibration[5];

  /*  L2 (forearm segment) length (m); segment length puts distal end in line with subject pointer */
  /* '<S236>:1:345' */
  robot_row[2] = calibration[6];

  /*  perpendicular distance from L2 to subject pointer (m) */
  /* '<S236>:1:346' */
  robot_row[3] = calibration[2];

  /*  shoulder x position (m) (global coordinates) */
  /* '<S236>:1:347' */
  robot_row[4] = calibration[3];

  /*  shoulder y position (m) (global coordinates) */
  /* '<S236>:1:348' */
  robot_row[5] = arm_orientation;

  /*  subject's expected arm orientation (1: right, 2: left) */
  /* '<S236>:1:349' */
  robot_row[6] = shoulder_angle;

  /*  shoulder joint angle, with correction for offsets (see above) (rad) */
  /* '<S236>:1:350' */
  robot_row[7] = elbow_angle;

  /*  elbow joint angle, with correction for offsets (see above) (rad) */
  /* '<S236>:1:351' */
  robot_row[8] = robot_data[2];

  /*  shoulder joint angular velocity (rad/s) */
  /* '<S236>:1:352' */
  robot_row[9] = elbow_velocity;

  /*  elbow joint angular velocity (rad/s) */
  /* '<S236>:1:353' */
  robot_row[10] = robot_data[4];

  /*  shoulder joint angular acceleration (rad/s^2) */
  /* '<S236>:1:354' */
  robot_row[11] = elbow_acceleration;

  /*  elbow joint angular acceleration (rad/s^2) */
  /* '<S236>:1:355' */
  robot_row[12] = torque_command[0];

  /*  commanded shoulder torque (Nm) */
  /* '<S236>:1:356' */
  robot_row[13] = torque_command[1];

  /*  commanded elbow torque (Nm) */
  /* '<S236>:1:357' */
  robot_row[14] = M1_torque_cmd;

  /*  commanded motor 1 torque (shoulder torque less elbow torque) (Nm) */
  /* '<S236>:1:358' */
  robot_row[15] = M2_torque_cmd;

  /*  commanded motor 2 torque (Nm) */
  /* '<S236>:1:359' */
  robot_row[16] = L1_angle;

  /*  upper arm angle with corrections, orientation-independent (see above) (rad) */
  /* '<S236>:1:360' */
  robot_row[17] = L2_angle;

  /*  forearm angle with corrections, orientation and shoulder-independent (see above) (rad) */
  /* '<S236>:1:361' */
  robot_row[18] = L1_velocity;

  /*  upper arm angular velocity, orientation-independent (see above) (rad/s) */
  /* '<S236>:1:362' */
  robot_row[19] = L2_velocity;

  /*  forearm angular velocity, orientation and shoulder-independent (see above) (rad/s) */
  /* '<S236>:1:363' */
  robot_row[20] = L1_acceleration;

  /*  upper arm angular acceleration, orientation-independent (see above) (rad/s^2) */
  /* '<S236>:1:364' */
  robot_row[21] = L2_acceleration;

  /*  forearm angular acceleration, orientation and shoulder-independent (see above) (rad/s^2) */
  /* '<S236>:1:365' */
  robot_row[22] = (calibration[5] * cos(L2_angle) + elbow_position_x) +
    calibration[6] * cos(pointer_angle);

  /*  fingertip position in x (m) */
  /* '<S236>:1:366' */
  robot_row[23] = (calibration[5] * sin(L2_angle) + elbow_position_y) +
    calibration[6] * sin(pointer_angle);

  /*  fingertip position in y (m) */
  /* '<S236>:1:367' */
  robot_row[24] = (elbow_velocity_x - calibration[5] * sin(L2_angle) *
                   L2_velocity) - calibration[6] * sin(pointer_angle) *
    L2_velocity;

  /*  fingertip velocity in x (m/s) */
  /* '<S236>:1:368' */
  robot_row[25] = (calibration[5] * cos(L2_angle) * L2_velocity +
                   elbow_velocity_y) + calibration[6] * cos(pointer_angle) *
    L2_velocity;

  /*  fingertip velocity in y (m/s) */
  /* '<S236>:1:369' */
  robot_row[26] = (elbow_acceleration_x - (L2_velocity * L2_velocity * cos
    (L2_angle) + sin(L2_angle) * L2_acceleration) * calibration[5]) -
    (L2_velocity * L2_velocity * cos(pointer_angle) + sin(pointer_angle) *
     L2_acceleration) * calibration[6];

  /*  fingertip acceleration in x (m/s^2) */
  /* '<S236>:1:370' */
  robot_row[27] = ((L2_velocity * L2_velocity * -sin(L2_angle) + cos(L2_angle) *
                    L2_acceleration) * calibration[5] + elbow_acceleration_y) +
    (L2_velocity * L2_velocity * -sin(pointer_angle) + cos(pointer_angle) *
     L2_acceleration) * calibration[6];

  /*  fingertip acceleration in y (m/s^2) */
  /* '<S236>:1:371' */
  robot_row[28] = elbow_position_x;

  /*  elbow position in x (m) */
  /* '<S236>:1:372' */
  robot_row[29] = elbow_position_y;

  /*  elbow position in y (m) */
  /* '<S236>:1:373' */
  robot_row[30] = elbow_velocity_x;

  /*  elbow velocity in x (m/s) */
  /* '<S236>:1:374' */
  robot_row[31] = elbow_velocity_y;

  /*  elbow velocity in y (m/s) */
  /* '<S236>:1:375' */
  robot_row[32] = elbow_acceleration_x;

  /*  elbow acceleration in x (m/s^2) */
  /* '<S236>:1:376' */
  robot_row[33] = elbow_acceleration_y;

  /*  elbow acceleration in y (m/s^2) */
  /* '<S236>:1:377' */
  robot_row[34] = robot_data[6];

  /*  filtered shoulder velocity from motion control card (rad/s) */
  /* '<S236>:1:378' */
  robot_row[35] = robot_data[7];

  /*  filtered elbow velocity from motion control card (rad/s) */
  /* '<S236>:1:379' */
  robot_row[36] = robot_data[9] * 2.0 + robot_data[8];

  /*  motor status (bitfield; each 0: motor enabled, 1: motor disabled/faulted) */
  /* '<S236>:1:380' */
  robot_row[37] = force_sensor_force_u;

  /*  force measured by force sensor along u in its local coordinate system (N) */
  /* '<S236>:1:381' */
  robot_row[38] = force_sensor_force_v;

  /*  force measured by force sensor along v in its local coordinate system (N) */
  /* '<S236>:1:382' */
  robot_row[39] = force_sensor_force_w;

  /*  force measured by force sensor along w in its local coordinate system (N) */
  /* '<S236>:1:383' */
  robot_row[40] = force_sensor_torque_u;

  /*  torque measured by force sensor along u in its local coordinate system (Nm) */
  /* '<S236>:1:384' */
  robot_row[41] = force_sensor_torque_v;

  /*  torque measured by force sensor along v in its local coordinate system (Nm) */
  /* '<S236>:1:385' */
  robot_row[42] = force_sensor_torque_w;

  /*  torque measured by force sensor along w in its local coordinate system (Nm) */
  /* '<S236>:1:386' */
  robot_row[43] = force_sensor_force_x;

  /*  force measured by force sensor along x in the global coordinate system (N) */
  /* '<S236>:1:387' */
  robot_row[44] = force_sensor_force_y;

  /*  force measured by force sensor along y in its local coordinate system (N) */
  /* '<S236>:1:388' */
  robot_row[45] = force_sensor_force_z;

  /*  force measured by force sensor along z in its local coordinate system (N) */
  /* '<S236>:1:389' */
  robot_row[46] = force_sensor_torque_x;

  /*  torque measured by force sensor along x in its local coordinate system (Nm) */
  /* '<S236>:1:390' */
  robot_row[47] = force_sensor_torque_y;

  /*  torque measured by force sensor along y in its local coordinate system (Nm) */
  /* '<S236>:1:391' */
  robot_row[48] = force_sensor_torque_z;

  /*  torque measured by force sensor along z in its local coordinate system (Nm) */
  /* '<S236>:1:392' */
  robot_row[49] = force_sensor_data[6];
}

/* Initial conditions for function-call system: '<S34>/createKINData' */
void gbyk_v4b_createKINData_Init(void)
{
  int32_T i;

  /* InitializeConditions for UnitDelay: '<S235>/Output' */
  gbyk_v4b_DW.Output_DSTATE_p = gbyk_v4b_P.Output_InitialCondition_b;

  /* InitializeConditions for MATLAB Function: '<S70>/record errors' */
  gbyk_v4b_DW.lastECATMessages_not_empty = false;
  for (i = 0; i < 300; i++) {
    gbyk_v4b_DW.memoryBuffer[i] = 0.0;
  }

  gbyk_v4b_DW.waitingMsgCount = 0.0;
  gbyk_v4b_DW.outCount = 0.0;
  gbyk_v4b_DW.sentCount = 0.0;

  /* End of InitializeConditions for MATLAB Function: '<S70>/record errors' */
}

/* Output and update for function-call system: '<S34>/createKINData' */
void gbyk_v4b_createKINData(void)
{
  real_T feed_forward_duration;
  real_T elbow_velocity;
  real_T elbow_acceleration;
  real_T shoulder_angle;
  real_T L2_angle;
  real_T L1_velocity;
  real_T L2_velocity;
  boolean_T b;
  uint32_T motorInt;
  int32_T i;
  real_T tmp[50];
  real_T tmp_0[294];

  /* DataStoreRead: '<S70>/Read' */
  memcpy(&gbyk_v4b_B.Read[0], &gbyk_v4b_DW.RobotCalibrations[0], sizeof(real_T) <<
         4U);

  /* DataStoreRead: '<S70>/Read HW' */
  memcpy(&gbyk_v4b_B.ReadHW[0], &gbyk_v4b_DW.HardwareSettings[0], 24U * sizeof
         (real_T));

  /* DataStoreRead: '<S70>/Read Kinematics' */
  memcpy(&gbyk_v4b_B.ReadKinematics[0], &gbyk_v4b_DW.Kinematics[0], 20U * sizeof
         (real_T));

  /* DataStoreRead: '<S70>/Servo Read' */
  gbyk_v4b_B.ServoRead = gbyk_v4b_DW.ServoUpdate;

  /* DataStoreRead: '<S70>/Delay Read' */
  gbyk_v4b_B.DelayRead[0] = gbyk_v4b_DW.DelayEstimates[0];
  gbyk_v4b_B.DelayRead[1] = gbyk_v4b_DW.DelayEstimates[1];
  gbyk_v4b_B.DelayRead[2] = gbyk_v4b_DW.DelayEstimates[2];
  gbyk_v4b_B.DelayRead[3] = gbyk_v4b_DW.DelayEstimates[3];

  /* DataStoreRead: '<S70>/Primary read' */
  memcpy(&gbyk_v4b_B.Primaryread[0], &gbyk_v4b_DW.PrimaryEncoderData[0], 12U *
         sizeof(real_T));

  /* DataStoreRead: '<S70>/Data Store Read' */
  gbyk_v4b_B.DataStoreRead_l = gbyk_v4b_DW.CalibrationButton;
  for (i = 0; i < 7; i++) {
    /* SignalConversion: '<S236>/TmpSignal ConversionAt SFunction Inport3' incorporates:
     *  MATLAB Function: '<S70>/Create KINARM Data Array'
     */
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_e[i] =
      gbyk_v4b_B.Switch_p[i];
  }

  for (i = 0; i < 7; i++) {
    /* SignalConversion: '<S236>/TmpSignal ConversionAt SFunction Inport3' incorporates:
     *  MATLAB Function: '<S70>/Create KINARM Data Array'
     */
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_e[i + 7] =
      gbyk_v4b_B.Switch1_b[i];
  }

  /* SignalConversion: '<S236>/TmpSignal ConversionAt SFunction Inport10' incorporates:
   *  Constant: '<S238>/Gaze Feedback Status'
   *  Constant: '<S238>/Hand Feedback Colour'
   *  Constant: '<S238>/Hand Feedback Feed Forward'
   *  Constant: '<S238>/Hand Feedback Radius'
   *  Constant: '<S238>/Hand Feedback Source'
   *  Constant: '<S238>/Hand Feedback Status'
   *  MATLAB Function: '<S70>/Create KINARM Data Array'
   */
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[0] =
    gbyk_v4b_P.HandFeedbackStatus_Value;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[1] =
    gbyk_v4b_P.HandFeedbackSource_Value;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[2] =
    gbyk_v4b_P.HandFeedbackRadius_Value;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[3] =
    gbyk_v4b_P.HandFeedbackColour_Value;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[4] =
    gbyk_v4b_P.HandFeedbackFeedForward_Value;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[5] =
    gbyk_v4b_P.GazeFeedbackStatus_Value;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[6] = gbyk_v4b_B.Gain;

  /* SignalConversion: '<S236>/TmpSignal ConversionAt SFunction Inport12' incorporates:
   *  MATLAB Function: '<S70>/Create KINARM Data Array'
   */
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[0] = gbyk_v4b_B.Convert3;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[1] = gbyk_v4b_B.Convert19[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[2] = gbyk_v4b_B.Convert19[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[3] = gbyk_v4b_B.Convert19[2];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[4] = gbyk_v4b_B.Convert1_p;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[5] =
    gbyk_v4b_B.RateTransition_kg[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[6] =
    gbyk_v4b_B.RateTransition_kg[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[7] =
    gbyk_v4b_B.RateTransition_kg[2];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[8] = gbyk_v4b_B.Convert4[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[9] = gbyk_v4b_B.Convert4[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[10] = gbyk_v4b_B.Convert4[2];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[11] =
    gbyk_v4b_B.pupil_GLOBAL[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[12] =
    gbyk_v4b_B.pupil_GLOBAL[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[13] =
    gbyk_v4b_B.pupil_GLOBAL[2];

  /* MATLAB Function: '<S70>/Create KINARM Data Array' incorporates:
   *  Constant: '<S70>/Dominant Arm'
   */
  /* MATLAB Function 'DataLogging/Poll KINARM/createKINData/Create KINARM Data Array': '<S236>:1' */
  /*  This function constructs a matrix of KINARM-related data called "KINdata". This matrix consists of three rows: the first two are each */
  /*  for data related to the respective robot (i.e. row 1 is for robot 1 data, row 2 for robot 2 data, etc.), and the third row is for data */
  /*  not specific to either arm. Each row of the matrix is currently of length 50, though not all elements in each row are used. */
  /* '<S236>:1:8' */
  for (i = 0; i < 150; i++) {
    gbyk_v4b_B.kinarm_data[i] = 0.0;
  }

  /* '<S236>:1:9' */
  for (i = 0; i < 12; i++) {
    gbyk_v4b_B.primary_encoder_data_out[i] = 0.0;
  }

  /*  Create the rows of robot-specific data. The utility function create_robot_row is used to assemble the values for each row.  */
  /*  The last section of that function (in which the row elements are assigned individually) documents the row contents. */
  /* '<S236>:1:13' */
  gbyk_v4b_create_robot_row(*(real_T (*)[8])&gbyk_v4b_B.Read[0], *(real_T (*)[12])
    &gbyk_v4b_B.ReadHW[0], *(real_T (*)[7])&
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_e[0], *(real_T (*)[10])&
    gbyk_v4b_B.ReadKinematics[0], *(real_T (*)[2])&gbyk_v4b_B.Memory[0], tmp);
  for (i = 0; i < 50; i++) {
    gbyk_v4b_B.kinarm_data[3 * i] = tmp[i];
  }

  /* '<S236>:1:16' */
  gbyk_v4b_create_robot_row(*(real_T (*)[8])&gbyk_v4b_B.Read[8], *(real_T (*)[12])
    &gbyk_v4b_B.ReadHW[12], *(real_T (*)[7])&
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_e[7], *(real_T (*)[10])&
    gbyk_v4b_B.ReadKinematics[10], *(real_T (*)[2])&gbyk_v4b_B.Memory[2], tmp);
  for (i = 0; i < 50; i++) {
    gbyk_v4b_B.kinarm_data[1 + 3 * i] = tmp[i];
  }

  /* normally the feed forward should be whatever Dex says it is. However, if the task's */
  /* process VCodes block has set an expected time to display targets then the */
  /* feed forward should reflect that number instead. */
  /* '<S236>:1:22' */
  feed_forward_duration = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[4];
  if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[6] >
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[4]) {
    /* '<S236>:1:23' */
    /* '<S236>:1:24' */
    feed_forward_duration = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[6];
  }

  /*  Create the last row of KINdata, which contains information not specific to any single arm. */
  /* '<S236>:1:28' */
  gbyk_v4b_B.kinarm_data[2] = gbyk_v4b_P.DominantArm_Value;

  /*  dominant KINARM for the experiment (1: arm 1, 2: arm 2) */
  /* '<S236>:1:29' */
  gbyk_v4b_B.kinarm_data[5] = feed_forward_duration;

  /*  duration of feed forward for position of hand feedback (s) */
  /* '<S236>:1:30' */
  gbyk_v4b_B.kinarm_data[8] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10
    [0];

  /*  hand feedback arm (0: none, 1: dominant, 2: non-dominant, 3: both, 4: controlled by task program) */
  /* '<S236>:1:31' */
  gbyk_v4b_B.kinarm_data[11] =
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[1];

  /*  hand feedback settings source (0: GUI, 1: from task program) */
  /* '<S236>:1:32' */
  gbyk_v4b_B.kinarm_data[14] =
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[3];

  /*  feedback colour (RRRGGGBBB string converted to integer) */
  /* '<S236>:1:33' */
  gbyk_v4b_B.kinarm_data[17] =
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[2];

  /*  feedback radius (m) */
  /* '<S236>:1:34' */
  gbyk_v4b_B.kinarm_data[20] =
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[4];

  /*  true feed forward requested by Dex in seconds */
  /* '<S236>:1:35' */
  gbyk_v4b_B.kinarm_data[23] = gbyk_v4b_B.DelayRead[0];

  /*  primary encoders velocity delay estimate (s) */
  /* '<S236>:1:36' */
  gbyk_v4b_B.kinarm_data[26] = gbyk_v4b_B.DelayRead[1];

  /*  primary encoders acceleration delay estimate (s) */
  /* '<S236>:1:37' */
  gbyk_v4b_B.kinarm_data[29] = gbyk_v4b_B.DelayRead[2];

  /*  secondary encoders velocity delay estimate (s) */
  /* '<S236>:1:38' */
  gbyk_v4b_B.kinarm_data[32] = gbyk_v4b_B.DelayRead[3];

  /*  secondary encoders acceleration delay estimate (s) */
  /* '<S236>:1:39' */
  gbyk_v4b_B.kinarm_data[35] = gbyk_v4b_B.ServoRead;

  /*  servo update count */
  /* '<S236>:1:40' */
  gbyk_v4b_B.kinarm_data[38] = gbyk_v4b_B.DataStoreRead_l;

  /*  EP calibration button status bitfield */
  /* '<S236>:1:42' */
  /* '<S236>:1:43' */
  gbyk_v4b_B.kinarm_data[41] =
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[0];

  /*  is Gaze tracking hardware available */
  /* '<S236>:1:44' */
  gbyk_v4b_B.kinarm_data[44] =
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[5];

  /*  Gaze feedback (0: on, 1: controlled by task program) */
  if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[0] != 0.0) {
    /* '<S236>:1:47' */
    gbyk_v4b_B.kinarm_data[47] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[1];

    /*  Gaze X location in global coordinates */
    /* '<S236>:1:48' */
    gbyk_v4b_B.kinarm_data[50] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[2];

    /*  Gaze Y location in global coordinates */
    /* '<S236>:1:49' */
    gbyk_v4b_B.kinarm_data[53] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[3];

    /*  Gaze Timestamp in seconds */
    /* '<S236>:1:50' */
    gbyk_v4b_B.kinarm_data[56] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[4];

    /*  Gaze pupil area */
    /* '<S236>:1:51' */
    gbyk_v4b_B.kinarm_data[59] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[5];

    /*  Gaze Event ID */
    /* '<S236>:1:52' */
    gbyk_v4b_B.kinarm_data[62] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[6];

    /*  Gaze Event start time in seconds */
    /* '<S236>:1:53' */
    gbyk_v4b_B.kinarm_data[65] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[7];

    /*  Gaze Event end time in seconds     */
    /* '<S236>:1:54' */
    gbyk_v4b_B.kinarm_data[68] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[8];

    /*  Gaze Vector X    */
    /* '<S236>:1:55' */
    gbyk_v4b_B.kinarm_data[71] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[9];

    /*  Gaze Vector Y    */
    /* '<S236>:1:56' */
    gbyk_v4b_B.kinarm_data[74] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[10];

    /*  Gaze Vector Z    */
    /* '<S236>:1:57' */
    gbyk_v4b_B.kinarm_data[77] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[11];

    /*  Gaze pupil loc X    */
    /* '<S236>:1:58' */
    gbyk_v4b_B.kinarm_data[80] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[12];

    /*  Gaze pupil loc Y    */
    /* '<S236>:1:59' */
    gbyk_v4b_B.kinarm_data[83] =
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[13];

    /*  Gaze pupil loc Z    */
  } else {
    /* '<S236>:1:61' */
    gbyk_v4b_B.kinarm_data[47] = -100.0;

    /*  Gaze X location in global coordinates */
    /* '<S236>:1:62' */
    gbyk_v4b_B.kinarm_data[50] = -100.0;

    /*  Gaze Y location in global coordinates */
    /* '<S236>:1:63' */
    gbyk_v4b_B.kinarm_data[53] = -100.0;

    /*  Gaze Timestamp in seconds */
    /* '<S236>:1:64' */
    gbyk_v4b_B.kinarm_data[56] = -100.0;

    /*  Gaze Timestamp in seconds */
    /* '<S236>:1:65' */
    gbyk_v4b_B.kinarm_data[68] = -100.0;

    /*  Gaze Vector X    */
    /* '<S236>:1:66' */
    gbyk_v4b_B.kinarm_data[71] = -100.0;

    /*  Gaze Vector Y    */
    /* '<S236>:1:67' */
    gbyk_v4b_B.kinarm_data[74] = -100.0;

    /*  Gaze Vector Z    */
    /* '<S236>:1:68' */
    gbyk_v4b_B.kinarm_data[77] = -100.0;

    /*  Gaze pupil loc X   */
    /* '<S236>:1:69' */
    gbyk_v4b_B.kinarm_data[80] = -100.0;

    /*  Gaze pupil loc Y    */
    /* '<S236>:1:70' */
    gbyk_v4b_B.kinarm_data[83] = -100.0;

    /*  Gaze pupil loc Z    */
  }

  /*  Create the two rows of primary encoder data. These outputs are analogous to the L1/L2 outputs in kinarm_data, the difference being that */
  /*  these are always derived from the primary encoders while the contents of kinarm_data is derived from the primary or secondary encoders */
  /*  (depending on the user's choice of whether or not to use the secondary encoders in the GUI). */
  /* '<S236>:1:76' */
  /* '<S236>:1:77' */
  /* '<S236>:1:79' */
  /* '<S236>:1:80' */
  /* '<S236>:1:81' */
  /* '<S236>:1:82' */
  elbow_velocity = gbyk_v4b_B.Primaryread[3];

  /* '<S236>:1:83' */
  /* '<S236>:1:84' */
  elbow_acceleration = gbyk_v4b_B.Primaryread[5];

  /* '<S236>:1:86' */
  /* '<S236>:1:87' */
  /* '<S236>:1:88' */
  /*  L1 (upper arm segment) length (m) */
  /* '<S236>:1:89' */
  /*  L3 error, the difference between lengths L3 and L5 (m) */
  /* '<S236>:1:91' */
  /* '<S236>:1:92' */
  /*  robot orientation (1: right-handed from robot perspective, -1: left-handed from robot perspective) */
  /* '<S236>:1:93' */
  /*  L5 segment length (m) */
  /* '<S236>:1:94' */
  /*  angle of L2 relative to L5 (rad) */
  /* '<S236>:1:95' */
  if ((gbyk_v4b_B.ReadHW[0] == 0.0) || (gbyk_v4b_B.ReadHW[0] == 2.0)) {
    /* '<S236>:1:96' */
    b = true;
  } else {
    /* '<S236>:1:96' */
    b = false;
  }

  /*  Before proceeding, the shoulder and elbow angles are shifted by the offsets determined by the calibration. If the calibration has been */
  /*  performed correctly, this ensures that the angle of 0 corresponds to when the arm is aligned with the coronal plane. In the case of the  */
  /*  elbow angle for a KINARM EXO, an extra correction is performed (using a utility function, and according to the current calibration) to  */
  /*  account for small imperfections in the parallelogram of KINARM links caused by differences in the lengths of L3 and L5 (which are  */
  /*  theoretically equal). */
  /* '<S236>:1:103' */
  shoulder_angle = gbyk_v4b_B.Primaryread[0] + gbyk_v4b_B.Read[0];

  /*  If the robot is an Exoskeleton, use the correct_elbow_angle function to account for imperfections on the KINARM robot parallelogram structure */
  if (b) {
    /* '<S236>:1:96' */
    gbyk_v4b_correct_elbow_angle(gbyk_v4b_B.Primaryread[1] + gbyk_v4b_B.Read[1],
      gbyk_v4b_B.Primaryread[3], gbyk_v4b_B.Primaryread[5], gbyk_v4b_B.ReadHW[3],
      gbyk_v4b_B.Read[4], gbyk_v4b_B.ReadHW[2], gbyk_v4b_B.Read[7],
      &feed_forward_duration, &elbow_velocity, &L2_velocity);

    /* '<S236>:1:108' */
    feed_forward_duration += gbyk_v4b_B.Primaryread[1] + gbyk_v4b_B.Read[1];

    /* '<S236>:1:109' */
    elbow_velocity += gbyk_v4b_B.Primaryread[3];

    /* '<S236>:1:110' */
    elbow_acceleration = gbyk_v4b_B.Primaryread[5] + L2_velocity;
  } else {
    /* '<S236>:1:112' */
    feed_forward_duration = gbyk_v4b_B.Primaryread[1] + gbyk_v4b_B.Read[1];
  }

  /* '<S236>:1:115' */
  /* '<S236>:1:116' */
  L2_angle = shoulder_angle + feed_forward_duration;

  /* '<S236>:1:118' */
  L1_velocity = gbyk_v4b_B.Primaryread[2];

  /* '<S236>:1:119' */
  L2_velocity = gbyk_v4b_B.Primaryread[2] + elbow_velocity;

  /* '<S236>:1:121' */
  elbow_velocity = gbyk_v4b_B.Primaryread[4];

  /* '<S236>:1:122' */
  feed_forward_duration = gbyk_v4b_B.Primaryread[4] + elbow_acceleration;

  /*  a robot_orientation < 0 means that the robot is left-handed from its perspective (i.e. if you look at the robot structure,  */
  /*  and pretend that it is a humanoid, the robot itself looks left-handed).  For an Exoskeleton robot, this is the */
  /*  robot that the left-hand of the subject grabs. For an EP robot, this is the robot that the subjec'ts right-hand grabs.   */
  if (gbyk_v4b_B.ReadHW[5] < 0.0) {
    /* '<S236>:1:128' */
    /* '<S236>:1:129' */
    shoulder_angle = -shoulder_angle + 3.1415926535897931;

    /* '<S236>:1:130' */
    L2_angle = -L2_angle + 3.1415926535897931;

    /* '<S236>:1:132' */
    L1_velocity = -gbyk_v4b_B.Primaryread[2];

    /* '<S236>:1:133' */
    L2_velocity = -L2_velocity;

    /* '<S236>:1:135' */
    elbow_velocity = -gbyk_v4b_B.Primaryread[4];

    /* '<S236>:1:136' */
    feed_forward_duration = -feed_forward_duration;
  }

  /* '<S236>:1:139' */
  gbyk_v4b_B.primary_encoder_data_out[0] = shoulder_angle;

  /* '<S236>:1:140' */
  gbyk_v4b_B.primary_encoder_data_out[2] = L2_angle;

  /* '<S236>:1:142' */
  gbyk_v4b_B.primary_encoder_data_out[4] = L1_velocity;

  /* '<S236>:1:143' */
  gbyk_v4b_B.primary_encoder_data_out[6] = L2_velocity;

  /* '<S236>:1:145' */
  gbyk_v4b_B.primary_encoder_data_out[8] = elbow_velocity;

  /* '<S236>:1:146' */
  gbyk_v4b_B.primary_encoder_data_out[10] = feed_forward_duration;

  /* '<S236>:1:76' */
  /* '<S236>:1:77' */
  /* '<S236>:1:79' */
  /* '<S236>:1:80' */
  /* '<S236>:1:81' */
  /* '<S236>:1:82' */
  elbow_velocity = gbyk_v4b_B.Primaryread[9];

  /* '<S236>:1:83' */
  /* '<S236>:1:84' */
  elbow_acceleration = gbyk_v4b_B.Primaryread[11];

  /* '<S236>:1:86' */
  /* '<S236>:1:87' */
  /* '<S236>:1:88' */
  /*  L1 (upper arm segment) length (m) */
  /* '<S236>:1:89' */
  /*  L3 error, the difference between lengths L3 and L5 (m) */
  /* '<S236>:1:91' */
  /* '<S236>:1:92' */
  /*  robot orientation (1: right-handed from robot perspective, -1: left-handed from robot perspective) */
  /* '<S236>:1:93' */
  /*  L5 segment length (m) */
  /* '<S236>:1:94' */
  /*  angle of L2 relative to L5 (rad) */
  /* '<S236>:1:95' */
  if ((gbyk_v4b_B.ReadHW[12] == 0.0) || (gbyk_v4b_B.ReadHW[12] == 2.0)) {
    /* '<S236>:1:96' */
    b = true;
  } else {
    /* '<S236>:1:96' */
    b = false;
  }

  /*  Before proceeding, the shoulder and elbow angles are shifted by the offsets determined by the calibration. If the calibration has been */
  /*  performed correctly, this ensures that the angle of 0 corresponds to when the arm is aligned with the coronal plane. In the case of the  */
  /*  elbow angle for a KINARM EXO, an extra correction is performed (using a utility function, and according to the current calibration) to  */
  /*  account for small imperfections in the parallelogram of KINARM links caused by differences in the lengths of L3 and L5 (which are  */
  /*  theoretically equal). */
  /* '<S236>:1:103' */
  shoulder_angle = gbyk_v4b_B.Primaryread[6] + gbyk_v4b_B.Read[8];

  /*  If the robot is an Exoskeleton, use the correct_elbow_angle function to account for imperfections on the KINARM robot parallelogram structure */
  if (b) {
    /* '<S236>:1:96' */
    gbyk_v4b_correct_elbow_angle(gbyk_v4b_B.Primaryread[7] + gbyk_v4b_B.Read[9],
      gbyk_v4b_B.Primaryread[9], gbyk_v4b_B.Primaryread[11], gbyk_v4b_B.ReadHW
      [15], gbyk_v4b_B.Read[12], gbyk_v4b_B.ReadHW[14], gbyk_v4b_B.Read[15],
      &feed_forward_duration, &elbow_velocity, &L2_velocity);

    /* '<S236>:1:108' */
    feed_forward_duration += gbyk_v4b_B.Primaryread[7] + gbyk_v4b_B.Read[9];

    /* '<S236>:1:109' */
    elbow_velocity += gbyk_v4b_B.Primaryread[9];

    /* '<S236>:1:110' */
    elbow_acceleration = gbyk_v4b_B.Primaryread[11] + L2_velocity;
  } else {
    /* '<S236>:1:112' */
    feed_forward_duration = gbyk_v4b_B.Primaryread[7] + gbyk_v4b_B.Read[9];
  }

  /* '<S236>:1:115' */
  /* '<S236>:1:116' */
  L2_angle = shoulder_angle + feed_forward_duration;

  /* '<S236>:1:118' */
  L1_velocity = gbyk_v4b_B.Primaryread[8];

  /* '<S236>:1:119' */
  L2_velocity = gbyk_v4b_B.Primaryread[8] + elbow_velocity;

  /* '<S236>:1:121' */
  elbow_velocity = gbyk_v4b_B.Primaryread[10];

  /* '<S236>:1:122' */
  feed_forward_duration = gbyk_v4b_B.Primaryread[10] + elbow_acceleration;

  /*  a robot_orientation < 0 means that the robot is left-handed from its perspective (i.e. if you look at the robot structure,  */
  /*  and pretend that it is a humanoid, the robot itself looks left-handed).  For an Exoskeleton robot, this is the */
  /*  robot that the left-hand of the subject grabs. For an EP robot, this is the robot that the subjec'ts right-hand grabs.   */
  if (gbyk_v4b_B.ReadHW[17] < 0.0) {
    /* '<S236>:1:128' */
    /* '<S236>:1:129' */
    shoulder_angle = -shoulder_angle + 3.1415926535897931;

    /* '<S236>:1:130' */
    L2_angle = -L2_angle + 3.1415926535897931;

    /* '<S236>:1:132' */
    L1_velocity = -gbyk_v4b_B.Primaryread[8];

    /* '<S236>:1:133' */
    L2_velocity = -L2_velocity;

    /* '<S236>:1:135' */
    elbow_velocity = -gbyk_v4b_B.Primaryread[10];

    /* '<S236>:1:136' */
    feed_forward_duration = -feed_forward_duration;
  }

  /* '<S236>:1:139' */
  gbyk_v4b_B.primary_encoder_data_out[1] = shoulder_angle;

  /* '<S236>:1:140' */
  gbyk_v4b_B.primary_encoder_data_out[3] = L2_angle;

  /* '<S236>:1:142' */
  gbyk_v4b_B.primary_encoder_data_out[5] = L1_velocity;

  /* '<S236>:1:143' */
  gbyk_v4b_B.primary_encoder_data_out[7] = L2_velocity;

  /* '<S236>:1:145' */
  gbyk_v4b_B.primary_encoder_data_out[9] = elbow_velocity;

  /* '<S236>:1:146' */
  gbyk_v4b_B.primary_encoder_data_out[11] = feed_forward_duration;

  /* '<S236>:1:76' */
  for (i = 0; i < 8; i++) {
    /* DataStoreRead: '<S70>/Status read1' */
    gbyk_v4b_B.Statusread1_e[i] = gbyk_v4b_DW.ECATDigitalInput[i];

    /* DataStoreRead: '<S70>/torque feedback1' */
    gbyk_v4b_B.torquefeedback1[i] = gbyk_v4b_DW.ECATExtraData[i];
  }

  /* UnitDelay: '<S235>/Output' */
  gbyk_v4b_B.Output_h = gbyk_v4b_DW.Output_DSTATE_p;

  /* Sum: '<S240>/FixPt Sum1' incorporates:
   *  Constant: '<S240>/FixPt Constant'
   */
  gbyk_v4b_B.FixPtSum1_o = gbyk_v4b_B.Output_h +
    gbyk_v4b_P.FixPtConstant_Value_n;

  /* Switch: '<S241>/FixPt Switch' incorporates:
   *  Constant: '<S241>/Constant'
   */
  if (gbyk_v4b_B.FixPtSum1_o > gbyk_v4b_P.WrapToZero_Threshold_o) {
    gbyk_v4b_B.FixPtSwitch_h = gbyk_v4b_P.Constant_Value_m;
  } else {
    gbyk_v4b_B.FixPtSwitch_h = gbyk_v4b_B.FixPtSum1_o;
  }

  /* End of Switch: '<S241>/FixPt Switch' */

  /* DataStoreRead: '<S70>/ErrMsgs' */
  memcpy(&gbyk_v4b_B.ErrMsgs[0], &gbyk_v4b_DW.ECATErrMsgs[0], 20U * sizeof
         (real_T));

  /* MATLAB Function: '<S70>/record errors' incorporates:
   *  Constant: '<S70>/step time'
   */
  /* MATLAB Function 'DataLogging/Poll KINARM/createKINData/record errors': '<S239>:1' */
  if (!gbyk_v4b_DW.lastECATMessages_not_empty) {
    /* '<S239>:1:5' */
    /* '<S239>:1:6' */
    memcpy(&gbyk_v4b_DW.lastECATMessages[0], &gbyk_v4b_B.ErrMsgs[0], 20U *
           sizeof(real_T));
    gbyk_v4b_DW.lastECATMessages_not_empty = true;
  }

  /* '<S239>:1:13' */
  /* copy over the errors from ethercat drives */
  /* '<S239>:1:16' */
  if (!((gbyk_v4b_DW.waitingMsgCount >= 50.0) || (!(gbyk_v4b_B.ErrMsgs[8] !=
         gbyk_v4b_DW.lastECATMessages[8])) || (!(gbyk_v4b_B.ErrMsgs[8] != 0.0))))
  {
    /* '<S239>:1:21' */
    /* '<S239>:1:22' */
    gbyk_v4b_DW.waitingMsgCount++;

    /* '<S239>:1:23' */
    i = (int32_T)gbyk_v4b_DW.waitingMsgCount - 1;
    gbyk_v4b_DW.memoryBuffer[i] = gbyk_v4b_B.Output_h;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[0]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[50 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[4]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[100 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[8]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[150 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[12]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[200 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[16]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[250 + i] = motorInt;
  } else {
    /* '<S239>:1:17' */
  }

  /* '<S239>:1:16' */
  if (!((gbyk_v4b_DW.waitingMsgCount >= 50.0) || (!(gbyk_v4b_B.ErrMsgs[9] !=
         gbyk_v4b_DW.lastECATMessages[9])) || (!(gbyk_v4b_B.ErrMsgs[9] != 0.0))))
  {
    /* '<S239>:1:21' */
    /* '<S239>:1:22' */
    gbyk_v4b_DW.waitingMsgCount++;

    /* '<S239>:1:23' */
    i = (int32_T)gbyk_v4b_DW.waitingMsgCount - 1;
    gbyk_v4b_DW.memoryBuffer[i] = gbyk_v4b_B.Output_h;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[1]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[50 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[5]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[100 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[9]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[150 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[13]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[200 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[17]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[250 + i] = motorInt;
  } else {
    /* '<S239>:1:17' */
  }

  /* '<S239>:1:16' */
  if (!((gbyk_v4b_DW.waitingMsgCount >= 50.0) || (!(gbyk_v4b_B.ErrMsgs[10] !=
         gbyk_v4b_DW.lastECATMessages[10])) || (!(gbyk_v4b_B.ErrMsgs[10] != 0.0))))
  {
    /* '<S239>:1:21' */
    /* '<S239>:1:22' */
    gbyk_v4b_DW.waitingMsgCount++;

    /* '<S239>:1:23' */
    i = (int32_T)gbyk_v4b_DW.waitingMsgCount - 1;
    gbyk_v4b_DW.memoryBuffer[i] = gbyk_v4b_B.Output_h;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[2]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[50 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[6]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[100 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[10]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[150 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[14]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[200 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[18]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[250 + i] = motorInt;
  } else {
    /* '<S239>:1:17' */
  }

  /* '<S239>:1:16' */
  if (!((gbyk_v4b_DW.waitingMsgCount >= 50.0) || (!(gbyk_v4b_B.ErrMsgs[11] !=
         gbyk_v4b_DW.lastECATMessages[11])) || (!(gbyk_v4b_B.ErrMsgs[11] != 0.0))))
  {
    /* '<S239>:1:21' */
    /* '<S239>:1:22' */
    gbyk_v4b_DW.waitingMsgCount++;

    /* '<S239>:1:23' */
    i = (int32_T)gbyk_v4b_DW.waitingMsgCount - 1;
    gbyk_v4b_DW.memoryBuffer[i] = gbyk_v4b_B.Output_h;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[3]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[50 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[7]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[100 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[11]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[150 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[15]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[200 + i] = motorInt;
    feed_forward_duration = rt_roundd_snf(gbyk_v4b_B.ErrMsgs[19]);
    if (feed_forward_duration < 4.294967296E+9) {
      if (feed_forward_duration >= 0.0) {
        motorInt = (uint32_T)feed_forward_duration;
      } else {
        motorInt = 0U;
      }
    } else {
      motorInt = MAX_uint32_T;
    }

    gbyk_v4b_DW.memoryBuffer[250 + i] = motorInt;
  } else {
    /* '<S239>:1:17' */
  }

  /* '<S239>:1:16' */
  /* '<S239>:1:27' */
  for (i = 0; i < 6; i++) {
    gbyk_v4b_B.newMessage[i] = 0.0;
  }

  /* if we have an error to send we must send it for a few frames because we only send */
  /* some frames to the GUI computer. The only safe way to handle this is to count */
  /* the number of real-time frames vs the frequency we send to the GUI computer on. */
  /* I wanted to use the actual frame number we send to the GUI, but the trouble is */
  /* we don't know which of the kinematic frames gets sent to the GUI, it's just one */
  /* of the 2 or 4 that happens for each frame we send to the GUI.  */
  /* So instead here I cop out and just count 2 or 4 frames and then send something new. */
  if (gbyk_v4b_DW.waitingMsgCount > 0.0) {
    /* '<S239>:1:35' */
    /* '<S239>:1:36' */
    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.newMessage[i] = gbyk_v4b_DW.memoryBuffer[50 * i];
    }

    /* '<S239>:1:37' */
    gbyk_v4b_DW.outCount++;

    /* we've sent the frame enough times... */
    if (gbyk_v4b_DW.outCount >= 0.001 / gbyk_v4b_P.steptime_Value) {
      /* '<S239>:1:40' */
      /* shift the list so the first row is the next thing to send. */
      /* '<S239>:1:42' */
      for (i = 0; i < 6; i++) {
        memcpy(&tmp_0[49 * i], &gbyk_v4b_DW.memoryBuffer[50 * i + 1], 49U *
               sizeof(real_T));
      }

      for (i = 0; i < 6; i++) {
        memcpy(&gbyk_v4b_DW.memoryBuffer[50 * i], &tmp_0[49 * i], 49U * sizeof
               (real_T));
      }

      /* '<S239>:1:43' */
      gbyk_v4b_DW.waitingMsgCount--;

      /* '<S239>:1:44' */
      gbyk_v4b_DW.sentCount++;

      /* '<S239>:1:45' */
      gbyk_v4b_DW.outCount = 0.0;

      /* if we still have another frame to send then copy it out.. */
      if (gbyk_v4b_DW.waitingMsgCount > 0.0) {
        /* '<S239>:1:48' */
        /* '<S239>:1:49' */
        for (i = 0; i < 6; i++) {
          gbyk_v4b_B.newMessage[i] = gbyk_v4b_DW.memoryBuffer[50 * i];
        }

        /* '<S239>:1:50' */
        gbyk_v4b_DW.outCount = 1.0;
      }
    }
  }

  /* '<S239>:1:55' */
  memcpy(&gbyk_v4b_DW.lastECATMessages[0], &gbyk_v4b_B.ErrMsgs[0], 20U * sizeof
         (real_T));

  /* '<S239>:1:56' */
  gbyk_v4b_B.sentMessageCount = gbyk_v4b_DW.sentCount;

  /* End of MATLAB Function: '<S70>/record errors' */

  /* DataTypeConversion: '<S70>/Data Type Conversion' */
  for (i = 0; i < 6; i++) {
    feed_forward_duration = floor(gbyk_v4b_B.newMessage[i]);
    if (rtIsNaN(feed_forward_duration) || rtIsInf(feed_forward_duration)) {
      feed_forward_duration = 0.0;
    } else {
      feed_forward_duration = fmod(feed_forward_duration, 4.294967296E+9);
    }

    gbyk_v4b_B.DataTypeConversion_nq[i] = feed_forward_duration < 0.0 ?
      (uint32_T)-(int32_T)(uint32_T)-feed_forward_duration : (uint32_T)
      feed_forward_duration;
  }

  /* End of DataTypeConversion: '<S70>/Data Type Conversion' */

  /* DataStoreRead: '<S70>/Status read' */
  for (i = 0; i < 7; i++) {
    gbyk_v4b_B.Statusread[i] = gbyk_v4b_DW.SystemStatus[i];
  }

  /* End of DataStoreRead: '<S70>/Status read' */

  /* MATLAB Function: '<S70>/bitpack' */
  /* MATLAB Function 'DataLogging/Poll KINARM/createKINData/bitpack': '<S237>:1' */
  /* '<S237>:1:2' */
  gbyk_v4b_B.statusInts[0] = 0U;
  gbyk_v4b_B.statusInts[1] = gbyk_v4b_B.Statusread[4];
  gbyk_v4b_B.statusInts[2] = gbyk_v4b_B.Statusread[5];
  gbyk_v4b_B.statusInts[3] = gbyk_v4b_B.Statusread[6];

  /*  STATUS_FUNCTIONING = uint32(0); */
  /*  STATUS_READY = uint32(1); */
  /*  STATUS_FAULTED = uint32(2); */
  /* '<S237>:1:8' */
  /* '<S237>:1:9' */
  /* '<S237>:1:10' */
  motorInt = gbyk_v4b_B.Statusread[0];

  /* '<S237>:1:9' */
  /* '<S237>:1:10' */
  motorInt |= gbyk_v4b_B.Statusread[1] << 2U;

  /* '<S237>:1:9' */
  /* '<S237>:1:10' */
  motorInt |= gbyk_v4b_B.Statusread[2] << 4U;

  /* '<S237>:1:9' */
  /* '<S237>:1:10' */
  motorInt |= gbyk_v4b_B.Statusread[3] << 6U;

  /* '<S237>:1:9' */
  /* '<S237>:1:12' */
  gbyk_v4b_B.statusInts[0] = motorInt;

  /* Update for UnitDelay: '<S235>/Output' */
  gbyk_v4b_DW.Output_DSTATE_p = gbyk_v4b_B.FixPtSwitch_h;
  gbyk_v4b_DW.createKINData_SubsysRanBC = 4;
}
