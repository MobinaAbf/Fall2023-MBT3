#include <iostream>
using namespace std;

class Matrix
{
    private:
    float **arr1, **arr2, **result;
    int size;

    public:
    Matrix();
    Matrix(int);
    Matrix(const Matrix &);
    ~Matrix();
    void getSize();
    void input();
    void sum();
    void subtraction();
    void multiplication();
    void inverse_2();
    void inverse_3();

};

/////////////////////////////////////////////////

void Matrix :: getSize()
{
    cout<<"1) 2*2 \n2) 3*3\n"<<"Select the matrix size : ";
    cin>>size;

    if(size == 1)
        size = 2;  
    else if(size == 2)
        size = 3;
}

/////////////////////////////////////////////////

void Matrix :: input()
{
    cout << "Enter Matrix 1 : \n";
    arr1 = new float *[size];
    for (int i = 0; i < size; i++)
    {
        arr1[i] = new float[size];
        for (int j = 0; j < size; j++)
        {
            cout << "[" << i << "][" << j << "] : ";
            cin >> arr1[i][j];
        }
    }

    cout << "Enter Matrix 2 : \n";
    arr2 = new float *[size];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = new float[size];
        for (int j = 0; j < size; j++)
        {
            cout << "[" << i << "][" << j << "] : ";
            cin >> arr2[i][j];
        }
    }
}

/////////////////////////////////////////////////


void Matrix :: sum()
{
    result = new float *[size];
    for (int i=0; i<size; i++){
        result[i] = new float [size];
        for(int j=0; j<size; j++){
            result[i][j]=arr1[i][j]+arr2[i][j];
            cout<<result[i][j]<<"\t";
        }
        cout<<endl;
    }
    delete []result;
}

/////////////////////////////////////////////////

void Matrix :: subtraction()
{
    result = new float *[size];
    for(int i=0; i<size; i++){
        result[i] = new float [size];
        for (int j=0; j<size; j++){
            result[i][j] = arr1[i][j] - arr2[i][j];
            cout<<result[i][j]<<"\t";
        }
        cout<<endl;
    }
    delete []result;
}

/////////////////////////////////////////////////

void Matrix :: multiplication()
{
    result = new float *[size];
    for(int i=0; i<size; i++){
        result[i] = new float[size];
        for (int j=0; j<size; j++){
            result[i][j]=0;
            for(int k=0; k<size; k++){
                result[i][j] += arr1[i][k] * arr2[k][j];
        }
    }
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<endl;
    }
    delete []result;

}

/////////////////////////////////////////////////

void Matrix :: inverse_2()
{
    if (size == 2){

        cout<<"\ninverse of matrix 1 :\n";
        float inv1[2][2];
        float d1;
        d1 = arr1[0][0] * arr1[1][1] - arr1[0][1] * arr1[1][0];
        if (d1!=0){
            inv1[0][0] = arr1[1][1];
            inv1[1][1] = arr1[0][0];
            inv1[0][1] =-arr1[0][1];
            inv1[1][0] =-arr1[1][0];

            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    cout<<inv1[i][j]/d1<<"\t";
                }
                cout<<endl;
            }   
        }
        else{
            cout<<"there is no inverse for 0 determinant of Matrix 1!\n";
        }

/////////////////////////////////////////////////

        cout<<"\ninverse of matrix 2 :\n";
        float inv2[2][2];
        float d2;
        d2 = arr1[0][0] * arr1[1][1] - arr1[0][1] * arr1[1][0];
        if (d2!=0){
            inv2[0][0] = arr2[1][1];
            inv2[1][1] = arr2[0][0];
            inv2[0][1] = -arr2[0][1];
            inv2[1][0] = -arr2[1][0];

            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    cout<<inv2[i][j]/d2<<"\t";
                }
                cout<<endl;
            }   
        }
        else{
            cout<<"there is no inverse for 0 determinant of Matrix 2!\n";
        }}}


/////////////////////////////////////////////////

void Matrix :: inverse_3()
{ 
    if (size == 3){

        cout<<"inverse of matrix 1 :\n\n";
        float determinant1 ;
        float matrix1[3][3];

        determinant1 =(
        arr1[0][0] * ( arr1[1][1] * arr1[2][2] - arr1[1][2] * arr1[2][1] )-
        arr1[0][1] * ( arr1[1][0] * arr1[2][2] - arr1[1][2] * arr1[2][0] )+
        arr1[0][2] * ( arr1[1][0] * arr1[2][1] - arr1[1][1] * arr1[2][0] )
    );
    if (determinant1 !=0 ){
        matrix1[0][0] = ( arr1[1][1] * arr1[2][2] - arr1[1][2] * arr1[2][1] ) / determinant1;
        matrix1[0][2] = ( arr1[0][1] * arr1[1][2] - arr1[0][2] * arr1[1][1] ) / determinant1;
        matrix1[1][0] =-( arr1[1][0] * arr1[2][2] - arr1[1][2] * arr1[2][0] ) / determinant1;
        matrix1[1][1] = ( arr1[0][0] * arr1[2][2] - arr1[0][2] * arr1[2][0] ) / determinant1;
        matrix1[1][2] =-( arr1[0][0] * arr1[1][2] - arr1[0][2] * arr1[1][0] ) / determinant1;
        matrix1[2][0] = ( arr1[1][0] * arr1[2][1] - arr1[1][1] * arr1[2][0] ) / determinant1;
        matrix1[2][1] =-( arr1[0][0] * arr1[2][1] - arr1[0][1] * arr1[2][0] ) / determinant1;
        matrix1[2][2] = ( arr1[0][0] * arr1[1][1] - arr1[0][1] * arr1[1][0] ) / determinant1;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<matrix1[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"determinant is zero \n"; 
    }

/////////////////////////////////////////////////

        cout<<"inverse of matrix 2 :\n\n";
        float determinant2 ;
        float matrix2[3][3];

        determinant2 =(
        arr2[0][0] * ( arr2[1][1] * arr2[2][2]- arr2[1][2] * arr2[2][1])-
        arr2[0][1] * ( arr2[1][0] * arr2[2][2]- arr2[1][2] * arr2[2][0])+
        arr2[0][2] * ( arr2[1][0] * arr2[2][1]- arr2[1][1] * arr2[2][0])
    );
    if (determinant2 !=0 ){
        matrix2[0][0] = ( arr2[1][1] * arr2[2][2] - arr2[1][2] * arr2[2][1] ) / determinant2;
        matrix2[0][1] =-( arr2[0][1] * arr2[2][2] - arr2[0][2] * arr2[2][1] ) / determinant2;
        matrix2[0][2] = ( arr2[0][1] * arr2[1][2] - arr2[0][2] * arr2[1][1] ) / determinant2;
        matrix2[1][0] =-( arr2[1][0] * arr2[2][2] - arr2[1][2] * arr2[2][0] ) / determinant2;
        matrix2[1][1] = ( arr2[0][0] * arr2[2][2] - arr2[0][2] * arr2[2][0] ) / determinant2;
        matrix2[1][2] =-( arr2[0][0] * arr2[1][2] - arr2[0][2] * arr2[1][0] ) / determinant2;
        matrix2[2][0] = ( arr2[1][0] * arr2[2][1] - arr2[1][1] * arr2[2][0] ) / determinant2;
        matrix2[2][1] =-( arr2[0][0] * arr2[2][1] - arr2[0][1] * arr2[2][0] ) / determinant2;
        matrix2[2][2] = ( arr2[0][0] * arr2[1][1] - arr2[0][1] * arr2[1][0] ) / determinant2;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<matrix2[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"determinant is zero \n";
    }
    }
   
}

/////////////////////////////////////////////////

Matrix :: Matrix()
{
   size = 2;
}

/////////////////////////////////////////////////

Matrix :: Matrix (int S)
{
   size = S;
}

/////////////////////////////////////////////////

Matrix :: Matrix (const Matrix & sample)
{
   size = sample.size;
}

/////////////////////////////////////////////////

Matrix :: ~ Matrix(){
    delete []arr1;
    delete []arr2;
}
/////////////////////////////////////////////////


int main(){
    int opr;

    Matrix matrix;
    matrix.getSize();
    matrix.input();

    cout<<"\n***********************\n";
    cout<<"1) Sum \n";
    cout<<"2) Multiplication \n";
    cout<<"3) Subtraction \n";
    cout<<"4) Reverse \n";
    cout<<"Select the operation : ";
    cin>>opr;

    
        switch (opr)
    {
        case 1:
            cout<<"sum is : \n";
            matrix.sum();
            break;
        case 2:
            cout<<"multiplication is : \n";
            matrix.multiplication();
            break;
        case 3:
            cout<<"subtraction is : ";
            matrix.subtraction();
            break;
        case 4:
            matrix.inverse_2();
            matrix.inverse_3();
            break;
    
        default:
            break;
    }
}