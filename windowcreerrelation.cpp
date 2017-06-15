#include "windowcreerrelation.h"

WindowCreerRelation::WindowCreerRelation(QWidget *parent):
QWidget(parent)
{
  setFixedSize(320,100);
  // vertical window
  V_window=new QVBoxLayout;

  //horizontal layout for form
  H_title=new QHBoxLayout;
  H_desc=new QHBoxLayout;
  H_orientee=new QHBoxLayout;

  // label for form
  lbl_title= new QLabel("Titre");
  lbl_desc= new QLabel("Description");
  lbl_orientee= new QLabel("Orientation");

  // form
  title=new QLineEdit;
  desc=new QLineEdit;
  orientee=new QComboBox;

  orientee->addItem("Non orientee");
  orientee->addItem("Orientee");

  H_buttons= new QHBoxLayout;

  valider = new QPushButton("Valider");

  annuler = new QPushButton("Fermer");
  connect(annuler, SIGNAL(clicked(bool)), this, SLOT(close()));

  //horizontal widget id
  H_title->addWidget(lbl_title);
  H_title->addWidget(title);

  //horizontal widget title
  H_desc->addWidget(lbl_desc);
  H_desc->addWidget(desc);

  //horizontal widget type_note
  H_orientee->addWidget(lbl_orientee);
  H_orientee->addWidget(orientee);

  //horizontal widget buttons valider/annuler
  H_buttons->addWidget(valider);
  H_buttons->addWidget(annuler);

  //Final vertical window layout
  V_window->addLayout(H_title);
  V_window->addLayout(H_desc);
  V_window->addLayout(H_orientee);
  V_window->addLayout(H_buttons);

  this->setLayout(V_window);
  }
