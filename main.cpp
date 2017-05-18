#include <QCoreApplication>
#include <QtWidgets>

class Window : public QWidget
{
public:
	Window(QWidget *parent = nullptr)
		: QWidget(parent)
	{
		QPushButton *button = new QPushButton(this);
		button->setSizePolicy(QSizePolicy::Expanding, 
				      QSizePolicy::Expanding);
		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(button);
		layout->setContentsMargins(80, 80, 80, 80);
		setLayout(layout);

		QStateMachine *machine = new QStateMachine(this);

		QState *s1 = new QState();
		s1->assignProperty(button, "text", "Outside");

		QState *s2 = new QState();
		s2->assignProperty(button, "text", "Inside");

		QEventTransition *enterTransition = 
			new QEventTransition(button, QEvent::Enter);
		enterTransition->setTargetState(s2);
		s1->addTransition(enterTransition);

		QEventTransition *leaveTransition =
			new QEventTransition(button, QEvent::MouseButtonPress);
		leaveTransition->setTargetState(s1);
		s2->addTransition(leaveTransition);
		
		QState *s3 = new QState();
		s3->assignProperty(button, "text", "Pressing...");

		QEventTransition *releaseTransition = 
			new QEventTransition(button, QEvent::MouseButtonRelease);
		releaseTransition->setTargetState(s2);
		s3->addTransition(releaseTransition);

		machine->addState(s1);
		machine->addState(s2);
		machine->addState(s3);

		machine->setInitialState(s1);
		machine->start();
	}
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	Window window;
	window.resize(300, 300);
	window.show();

	return app.exec();
}
