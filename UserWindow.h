#pragma once

#include <QWidget>
#include "ui_UserWindow.h"

#include "Observer.h"
#include "Controller.h"

class UserWindow : public QWidget,public Observer
{
	Q_OBJECT

public:
	UserWindow(Controller& controller,std::string name,std::string type, QWidget *parent = Q_NULLPTR);
	void update() override;
	void addIssue();
	void deleteIssue(QListWidgetItem* item);//
	void deleteIssueClicked();//
	void updateIssue();
	void connectFunction();
	void clikedItem();
	~UserWindow();
private:
	std::string name;
	std::string type;
	Controller& controller;
	QListWidgetItem* item;
private:
	Ui::UserWindow ui;
};
