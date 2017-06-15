#include "wcreercouple.h"

WindowCreerCouple::WindowCreerCouple(QWidget *parent):
  QWidget(parent)
{
  setFixedSize(320,100);
  // vertical window
  V_window=new QVBoxLayout;

  //horizontal layout for form
  H_note1=new QHBoxLayout;
  H_note2=new QHBoxLayout;
  H_label=new QHBoxLayout;

  // label for form
  lbl_note1= new QLabel("Id note 1");
  lbl_note2= new QLabel("Id note 2");
  lbl_label= new QLabel("Label");

  // form
  note1=new QLineEdit;
  note2=new QLineEdit;
  label=new QLineEdit;


  H_buttons= new QHBoxLayout;

  valider = new QPushButton("Valider");

  annuler = new QPushButton("Fermer");
  connect(annuler, SIGNAL(clicked(bool)), this, SLOT(close()));

  //horizontal widget id
  H_note1->addWidget(lbl_note1);
  H_note1->addWidget(note1);

  //horizontal widget id
  H_note2->addWidget(lbl_note2);
  H_note2->addWidget(note2);

  //horizontal widget type_note
  H_label->addWidget(lbl_label);
  H_label->addWidget(label);

  //horizontal widget buttons valider/annuler
  H_buttons->addWidget(valider);
  H_buttons->addWidget(annuler);

  //Final vertical window layout
  V_window->addLayout(H_note1);
  V_window->addLayout(H_note2);
  V_window->addLayout(H_label);
  V_window->addLayout(H_buttons);

  this->setLayout(V_window);
  }
