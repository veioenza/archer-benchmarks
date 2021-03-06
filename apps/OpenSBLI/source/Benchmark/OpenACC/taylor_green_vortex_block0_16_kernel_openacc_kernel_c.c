//
// auto-generated by ops.py
//
#include "./OpenACC/OpenSBLI_common.h"

#define OPS_GPU

int xdim0_taylor_green_vortex_block0_16_kernel;
int ydim0_taylor_green_vortex_block0_16_kernel;
int xdim1_taylor_green_vortex_block0_16_kernel;
int ydim1_taylor_green_vortex_block0_16_kernel;
int xdim2_taylor_green_vortex_block0_16_kernel;
int ydim2_taylor_green_vortex_block0_16_kernel;
int xdim3_taylor_green_vortex_block0_16_kernel;
int ydim3_taylor_green_vortex_block0_16_kernel;
int xdim4_taylor_green_vortex_block0_16_kernel;
int ydim4_taylor_green_vortex_block0_16_kernel;


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4


#define OPS_ACC0(x,y,z) (x+xdim0_taylor_green_vortex_block0_16_kernel*(y)+xdim0_taylor_green_vortex_block0_16_kernel*ydim0_taylor_green_vortex_block0_16_kernel*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_taylor_green_vortex_block0_16_kernel*(y)+xdim1_taylor_green_vortex_block0_16_kernel*ydim1_taylor_green_vortex_block0_16_kernel*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_taylor_green_vortex_block0_16_kernel*(y)+xdim2_taylor_green_vortex_block0_16_kernel*ydim2_taylor_green_vortex_block0_16_kernel*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_taylor_green_vortex_block0_16_kernel*(y)+xdim3_taylor_green_vortex_block0_16_kernel*ydim3_taylor_green_vortex_block0_16_kernel*(z))
#define OPS_ACC4(x,y,z) (x+xdim4_taylor_green_vortex_block0_16_kernel*(y)+xdim4_taylor_green_vortex_block0_16_kernel*ydim4_taylor_green_vortex_block0_16_kernel*(z))

//user function
inline
void taylor_green_vortex_block0_16_kernel(double *rhou1 , double *rhoE , double *rho , double *rhou2 , double *rhou0 , const int *idx)
{
double x = deltai0*idx[0];
double y = deltai1*idx[1];
double z = deltai2*idx[2];
double u = sin(x)*cos(y)*cos(z);
double v = -cos(x)*sin(y)*cos(z);
double w = 0.0;
double p = 1.0*rinv15 + 0.0625*(cos(2.0*x) + cos(2.0*y))*(2.0 + cos(2.0*z));
double r = gama*pow(Minf, 2)*p;
rho[OPS_ACC2(0,0,0)] = r;
rhou0[OPS_ACC4(0,0,0)] = r*u;
rhou1[OPS_ACC0(0,0,0)] = r*v;
rhou2[OPS_ACC3(0,0,0)] = 0.0;
rhoE[OPS_ACC1(0,0,0)] = rinv13*p + 0.5*r*(pow(u, 2) + pow(v, 2) + pow(w, 2));
}


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4



void taylor_green_vortex_block0_16_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  int *p_a5,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        int arg_idx[] = {arg_idx0+n_x, arg_idx1+n_y, arg_idx2+n_z};
        taylor_green_vortex_block0_16_kernel(  p_a0 + n_x*1*1 + n_y*xdim0_taylor_green_vortex_block0_16_kernel*1*1 + n_z*xdim0_taylor_green_vortex_block0_16_kernel*ydim0_taylor_green_vortex_block0_16_kernel*1,
           p_a1 + n_x*1*1 + n_y*xdim1_taylor_green_vortex_block0_16_kernel*1*1 + n_z*xdim1_taylor_green_vortex_block0_16_kernel*ydim1_taylor_green_vortex_block0_16_kernel*1,
           p_a2 + n_x*1*1 + n_y*xdim2_taylor_green_vortex_block0_16_kernel*1*1 + n_z*xdim2_taylor_green_vortex_block0_16_kernel*ydim2_taylor_green_vortex_block0_16_kernel*1,
           p_a3 + n_x*1*1 + n_y*xdim3_taylor_green_vortex_block0_16_kernel*1*1 + n_z*xdim3_taylor_green_vortex_block0_16_kernel*ydim3_taylor_green_vortex_block0_16_kernel*1,
           p_a4 + n_x*1*1 + n_y*xdim4_taylor_green_vortex_block0_16_kernel*1*1 + n_z*xdim4_taylor_green_vortex_block0_16_kernel*ydim4_taylor_green_vortex_block0_16_kernel*1,
          arg_idx );

      }
    }
  }
}
