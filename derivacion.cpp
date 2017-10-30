#include "derivacion.h"
#include "ui_derivacion.h"
#include<QString> //Bookstore for the use of text strings
#include<cmath>  //Library for use of mathematical function
Derivacion::Derivacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Derivacion)
{
    ui->setupUi(this);
    //Connections
    connect(ui->Calcular,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

Derivacion::~Derivacion()
{
    delete ui;
}
void Derivacion::metodo(){
    //Declaration of variables to print results
    QString temp, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11, temp12, temp13, temp14, temp15, temp16, temp17, temp18, temp19, temp20, temp21, temp22, temp23, temp24, temp25;
    QString temp26, temp27, temp28, temp29, temp30, temp31, temp32, temp33, temp34, temp35, temp36, temp37, temp38, temp39, temp40, temp41, temp42, temp43, temp44, temp45, temp46, temp47, temp48, temp49, temp50, temp51, temp52, temp53, temp54;
    //Variables in program
    double x=ui->X->value();
    double xme1=ui->Xme1->value();
    double xme2=ui->Xme2->value();
    double xme3=ui->Xme3->value();
    double xme4=ui->Xme4->value();
    double xme5=ui->Xme5->value();
    double xma1=ui->Xma1->value();
    double xma2=ui->Xma2->value();
    double xma3=ui->Xma3->value();
    double xma4=ui->Xma4->value();
    double xma5=ui->Xma5->value();
    double fx=ui->FX->value();
    double fxme1=ui->FXme1->value();
    double fxme2=ui->FXme2->value();
    double fxme3=ui->FXme3->value();
    double fxme4=ui->FXme4->value();
    double fxme5=ui->FXme5->value();
    double fxma1=ui->FXma1->value();
    double fxma2=ui->FXma2->value();
    double fxma3=ui->FXma3->value();
    double fxma4=ui->FXma4->value();
    double fxma5=ui->FXma5->value();
    double H=ui->h->value();
    double f1c=0, f2c=0, f3c=0, f4c=0, f11c=0, f22c=0, f33c=0, f44c=0;
    double f1at=0, f2at=0, f3at=0, f4at=0, f11at=0, f22at=0, f33at=0, f44at=0;
    double f1ad=0, f2ad=0, f3ad=0, f4ad=0, f11ad=0, f22ad=0, f33ad=0, f44ad=0;
    double err1c=0, err11c=0, err2c=0, err22c=0, err3c=0, err33c=0, err4c=0, err44c=0;
    double err1at=0, err11at=0, err2at=0, err22at=0, err3at=0, err33at=0, err4at=0, err44at=0;
    double err1ad=0, err11ad=0, err2ad=0, err22ad=0, err3ad=0, err33ad=0, err4ad=0, err44ad=0;
    //Centered Derivative
    f1c=(fxma1-fxme1)/(2*H);
    f11c=(-(fxma2)+(8*fxma1)-(8*fxme1)+(fxme2))/(12*H);
    f2c=(fxma1-(2*fx)+fxme1)/(H*H);
    f22c=(-fxma2+(16*fxma1)-(30*fx)+(16*fxme1)-fxme2)/(12*(H*H));
    f3c=(fxme2-(2*fxma1)+(2*fxme1)-fxme2)/(2*(H*H*H));
    f33c=(-fxma3+(8*fxma2)-(13*fxma1)+(13*fxme1)-(8*fxme2)+(fxme3))/(8*(H*H*H));
    f4c=(fxma2-(4*fxma1)+(6*fx)-(4*fxme1)+(fxme2))/(H*H*H*H);
    f44c=(-fxma3+(12*fxma2)+(39*fxma1)+(56*fx)-(39*fxme1)+(12*fxme2)+fxme3)/(6*(H*H*H*H));
    //Percent errors of derivatives centered
    err1c=100*std::abs((f1c-f11c)/f11c);
    err11c=100*std::abs((f11c-f11c)/f11c);
    err2c=100*std::abs((f2c-f11c)/f11c);
    err22c=100*std::abs((f22c-f11c)/f11c);
    err3c=100*std::abs((f3c-f11c)/f11c);
    err33c=100*std::abs((f33c-f11c)/f11c);
    err4c=100*std::abs((f4c-f11c)/f11c);
    err44c=100*std::abs((f44c-f11c)/f11c);
    //Impression of centered derivative results
    temp.append("Derivada centrada\nPrimera derivada sencilla=").append(temp1.setNum(f1c)).append("\nPrimera derivada completa=").append(temp2.setNum(f11c)).append("\nSegunda derivada sencilla=").append(temp3.setNum(f2c));
    temp.append("\nSegunda derivada completa=").append(temp4.setNum(f22c)).append("\nTercera Derivada sencilla=").append(temp5.setNum(f3c)).append("\nTercera derivada completa=").append(temp6.setNum(f33c)).append("\nCuarta derivada sencilla=").append(temp7.setNum(f4c)).append("\nCuarta derivada completa=").append(temp8.setNum(f44c));
    temp.append("\nErrores\nError 1° derivada sencilla=").append(temp9.setNum(err1c)).append("\nError 1° derivada completa=").append(temp10.setNum(err11c)).append("\nError 2° derivada sencilla=").append(temp11.setNum(err2c)).append("\nError 2° derivada completa=").append(temp12.setNum(err22c)).append("\nError 3° derivada sencilla=").append(temp13.setNum(err3c)).append("\nError 3° derivada completa=").append(temp14.setNum(err33c)).append("\nError 4° derivada sencilla=").append(temp15.setNum(err4c)).append("\nError 4° derivada completa=").append(temp16.setNum(err44c));
    //Derivative back
    f1at=(fx-fxme1)/H;
    f11at=((3*fx)-(4*fxme1)+(fxme2))/(2*H);
    f2at=(fx-(2*fxme1)+fxme2)/(H*H);
    f22at=((2*fx)-(5*fxme1)+(4*fxme2)-fxme3)/(H*H);
    f3at=(fx-(3*fxme1)+(3*fxme2)-fxme3)/(H*H*H);
    f33at=((5*fx)-(18*fxme1)+(24*fxme2)-(14*fxme3)+(3*fxme4))/(2*(H*H*H));
    f4at=(fx-(4*fxme1)+(6*fxme2)-(4*fxme3)+fxme4)/(H*H*H*H);
    f44at=((3*fx)-(14*fxme1)+(26*fxme2)-(24*fxme3)+(11*fxme4)-(2*fxme5))/(H*H*H*H);
     //Percentage Errors of Derivatives Backwards
    err1at=100*std::abs((f1at-f11c)/f11c);
    err11at=100*std::abs((f11at-f11c)/f11c);
    err2at=100*std::abs((f2at-f11c)/f11c);
    err22at=100*std::abs((f22at-f11c)/f11c);
    err3at=100*std::abs((f3at-f11c)/f11c);
    err33at=100*std::abs((f33at-f11c)/f11c);
    err4at=100*std::abs((f4at-f11c)/f11c);
    err44at=100*std::abs((f44at-f11c)/f11c);
    //Printing derivative results backwards
    temp.append("\nDerivada hacia atras\nPrimera derivada sencilla=").append(temp17.setNum(f1at)).append("\nPrimera derivada completa=").append(temp18.setNum(f11at)).append("\nSegunda derivada sencilla=").append(temp19.setNum(f2at));
    temp.append("\nSegunda derivada completa=").append(temp20.setNum(f22at)).append("\nTercera Derivada sencilla=").append(temp21.setNum(f3at)).append("\nTercera derivada completa=").append(temp22.setNum(f33at)).append("\nCuarta derivada sencilla=").append(temp23.setNum(f4at)).append("\nCuarta derivada completa=").append(temp24.setNum(f44at));
    temp.append("\nErrores\nError 1° derivada sencilla=").append(temp25.setNum(err1at)).append("\nError 1° derivada completa=").append(temp26.setNum(err11at)).append("\nError 2° derivada sencilla=").append(temp27.setNum(err2at)).append("\nError 2° derivada completa=").append(temp28.setNum(err22at)).append("\nError 3° derivada sencilla=").append(temp29.setNum(err3at)).append("\nError 3° derivada completa=").append(temp30.setNum(err33at)).append("\nError 4° derivada sencilla=").append(temp31.setNum(err4at)).append("\nError 4° derivada completa=").append(temp32.setNum(err44at));
    //Derived from forward
    f1ad=(fxma1-fx)/H;
    f11ad=(-fxma2+(4*fxma1)-(3*fx))/(2*H);
    f2ad=(fxma2-(2*fxma1)+fx)/(H*H);
    f22ad=(-fxma3+(4*fxma2)-(5*fxma1)+(2*fx))/(H*H);
    f3ad=(fxma3-(3*fxma2)+(3*fxma1)-fx)/(H*H*H);
    f33ad=(-(3*fxma4)+(14*fxma3)-(24*fxma2)+(18*fxma1)-(5*fx))/(2*(H*H*H));
    f4ad=(fxma4-(4*fxma3)+(6*fxma2)-(4*fxma1)+fx)/(H*H*H*H);
    f44ad=(-(2*fxma5)+(11*fxma4)-(24*fxma3)+(26*fxma2)-(14*fxma1)+(3*fx))/(H*H*H*H);
     //Percent errors of forward derivatives
    err1ad=100*std::abs((f1ad-f11c)/f11c);
    err11ad=100*std::abs((f11ad-f11c)/f11c);
    err2ad=100*std::abs((f2ad-f11c)/f11c);
    err22ad=100*std::abs((f22ad-f11c)/f11c);
    err3ad=100*std::abs((f3ad-f11c)/f11c);
    err33ad=100*std::abs((f33ad-f11c)/f11c);
    err4ad=100*std::abs((f4ad-f11c)/f11c);
    err44ad=100*std::abs((f44ad-f11c)/f11c);
     //Printing Forward Derivative Results
    temp.append("\nDerivada hacia adelante\nPrimera derivada sencilla=").append(temp33.setNum(f1ad)).append("\nPrimera derivada completa=").append(temp34.setNum(f11ad)).append("\nSegunda derivada sencilla=").append(temp35.setNum(f2ad));
    temp.append("\nSegunda derivada completa=").append(temp36.setNum(f22ad)).append("\nTercera Derivada sencilla=").append(temp37.setNum(f3ad)).append("\nTercera derivada completa=").append(temp38.setNum(f33ad)).append("\nCuarta derivada sencilla=").append(temp39.setNum(f4ad)).append("\nCuarta derivada completa=").append(temp40.setNum(f44ad));
    temp.append("\nErrores\nError 1° derivada sencilla=").append(temp41.setNum(err1ad)).append("\nError 1° derivada completa=").append(temp42.setNum(err11ad)).append("\nError 2° derivada sencilla=").append(temp43.setNum(err2ad)).append("\nError 2° derivada completa=").append(temp44.setNum(err22ad)).append("\nError 3° derivada sencilla=").append(temp45.setNum(err3ad)).append("\nError 3° derivada completa=").append(temp46.setNum(err33ad)).append("\nError 4° derivada sencilla=").append(temp47.setNum(err4ad)).append("\nError 4° derivada completa=").append(temp48.setNum(err44ad));
    ui->texto->setText(temp);
}

void Derivacion::borrar(){//Delete function
    ui->X->setValue(0.0);
    ui->Xme1->setValue(0.0);
    ui->Xme2->setValue(0.0);
    ui->Xme3->setValue(0.0);
    ui->Xme4->setValue(0.0);
    ui->Xme5->setValue(0.0);
    ui->Xma1->setValue(0.0);
    ui->Xma2->setValue(0.0);
    ui->Xma3->setValue(0.0);
    ui->Xma4->setValue(0.0);
    ui->Xma5->setValue(0.0);
    ui->FXme1->setValue(0.0);
    ui->FXme2->setValue(0.0);
    ui->FXme3->setValue(0.0);
    ui->FXme4->setValue(0.0);
    ui->FXme5->setValue(0.0);
    ui->FXma1->setValue(0.0);
    ui->FXma2->setValue(0.0);
    ui->FXma3->setValue(0.0);
    ui->FXma4->setValue(0.0);
    ui->FXma5->setValue(0.0);
    ui->FX->setValue(0.0);
    ui->h->setValue(0.0);
     ui->texto->clear();
}
