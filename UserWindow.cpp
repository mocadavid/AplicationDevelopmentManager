#include "UserWindow.h"
#include <algorithm>
#include <QMessageBox>

UserWindow::UserWindow(Controller& controller, std::string name, std::string type, QWidget *parent)
	: controller{controller}, name {name}, type{ type }, QWidget(parent)
{
	ui.setupUi(this);
	this->ui.labelName->setText(QString::fromStdString(name));
	this->ui.labelType->setText(QString::fromStdString(type));
	this->update();
	this->connectFunction();
	
}

void UserWindow::update() {
	this->ui.listWidgetIssues->clear();
	std::vector<Issue> issues = this->controller.getIssues();
	std::sort(issues.begin(), issues.end(), [](Issue issue1, Issue issue2) {return issue1.getStatus() > issue2.getStatus(); });
	std::sort(issues.begin(), issues.end(), [](Issue issue1, Issue issue2) {return issue1.getDescription() < issue2.getDescription(); });
	for (auto issue : issues) {
		new QListWidgetItem{ issue.toString().c_str(),this->ui.listWidgetIssues };
	}
}

UserWindow::~UserWindow()
{
}

void UserWindow::addIssue() {
	if (this->type == "tester") {
		if (!this->ui.lineEditDescription->text().isEmpty()) {
			Issue issue{ this->ui.lineEditDescription->text().toStdString(),"open",this->name,"None" };
			this->controller.addIssue(issue);
		}
		else {
			QMessageBox message;
			message.setText("Empty description!");
			message.exec();
		}
	}
}

void UserWindow::updateIssue() {
	if (this->type == "programmer") {
		
		char buffer[50];
		strcpy(buffer, this->item->text().toStdString().c_str());
		
		char* word = strtok(buffer, ",");
		std::string description{ word };
		
		this->controller.updateIssue(description,this->name);
	}
}

void UserWindow::clikedItem() {
	this->item = this->ui.listWidgetIssues->currentItem();
}

void UserWindow::connectFunction() {
	QObject::connect(this->ui.pushButtonAdd, &QPushButton::clicked, this, &UserWindow::addIssue);
	QObject::connect(this->ui.pushButtonSolve, &QPushButton::clicked, this, &UserWindow::updateIssue);
	QObject::connect(this->ui.listWidgetIssues, &QListWidget::itemPressed, this, &UserWindow::clikedItem);
	QObject::connect(this->ui.pushButtonRemove, &QPushButton::clicked, this, &UserWindow::deleteIssueClicked);
}

void UserWindow::deleteIssue(QListWidgetItem* item) {
	/*this->item = this->ui.listWidgetIssues->currentItem();
	QMessageBox mm;
	mm.setText(this->item->text());
	mm.exec();*/
}

void UserWindow::deleteIssueClicked() {
	char text[50];
	strcpy(text, this->item->text().toStdString().c_str());
	char* description = strtok(text, ",");
	this->item = NULL;
	this->controller.deleteIssue(description);
}