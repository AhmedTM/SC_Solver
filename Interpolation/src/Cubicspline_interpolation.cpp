#include "Cubicspline_interpolation.h"


Cubicspline_interpolation::Cubicspline_interpolation()
{ 
}


void Cubicspline_interpolation::fit(std::vector<double> x, std::vector<double> y)
{ 
    //Number of data points
    int n_ = x.size() - 1;
    //Init vectors
    si_.resize(n_ +1, 0.0);
    a_.resize(n_, 0.0);
    b_.resize(n_, 0.0);
    c_.resize(n_, 0.0);
    d_.resize(n_, 0.0);
    h_.resize(n_, 0.0);
	x_ = x;
    //Generate intervals vec
    for(int i=0;i<n_;i++)
    {
        h_[i]=x[i+1]-x[i];
    }
    //Generate Tri Matrix
    delete S_;
    S_ = new matrix<double>(n_-1, n_);
    gen_trimat(y, n_);
    //Gauss elimination
    std::vector<double> si_temp;
    si_temp.resize(n_-1);
    gaussElim(*S_, si_temp);
    for(int i=1;i<n_;i++)
    {
        si_[i]=si_temp[i-1];
    }
    //Calculate coffs
	Calc_Coeff(y);
}

double Cubicspline_interpolation::interpolate(double x)
{
	int interval_idx;
	for (interval_idx = 0; interval_idx < a_.size(); interval_idx++)
	{
		if ( (x >= x_[interval_idx]) && (x <= x_[interval_idx+1]) )
		{
			break;
		}
	}
	
	x = (x - x_[interval_idx]);

	return (a_[interval_idx] * x*x*x) + (b_[interval_idx] * x*x) + (c_[interval_idx] * x) + d_[interval_idx];
}

Cubicspline_interpolation::~Cubicspline_interpolation()
{ 
    delete S_;
}


void Cubicspline_interpolation::gen_trimat(std::vector<double> y_func, int n)
{
    for(int i=0;i<n-1;i++)
    {
        (*S_)[i][i]=2*(h_[i]+h_[i+1]);
    }

    for(int i=0;i<n-2;i++)
    {
        (*S_)[i][i+1]=h_[i+1];
        (*S_)[i+1][i]=h_[i+1];
    }

    for(int i=1;i<n;i++)
    {
        (*S_)[i-1][n-1]=(y_func[i+1]-y_func[i])*6.0/(double)h_[i]-(y_func[i]-y_func[i-1])*6.0/(double)h_[i-1];
    }
}

void Cubicspline_interpolation::gaussElim(matrix<double> a,std::vector<double>& x)
{
    double term;
    int n = x.size() + 1;
    int m = x.size();

    for(int i=0;i<m-1;i++)
    {
        //Begin Gauss Elimination
        for(int k=i+1;k<m;k++)
        {
            term=a[k][i]/ a[i][i];
            for(int j=0;j<n;j++)
            {
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }
    }

    //Begin Back-substitution
    for(int i=m-1;i>=0;i--)
    {
        x[i]=a[i][n-1];
        for(int j=i+1;j<n-1;j++)
        {
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }
             
}


void Cubicspline_interpolation::Calc_Coeff( std::vector<double> y){
    for(int i=0;i<a_.size();i++)
    {
        d_[i]=y[i];
        b_[i]=si_[i]/2.0;
        a_[i]=(si_[i+1]-si_[i])/(h_[i]*6.0);
        c_[i]=(y[i+1]-y[i])/h_[i]-h_[i]*(2.0*si_[i]+si_[i+1])/6.0;
    }
}