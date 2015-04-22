#include "resultslogger.h"

ResultsLogger::ResultsLogger(QString outputDirectoryPath, Model* m)
{
    output_directory_path = outputDirectoryPath;

    header.push_back("PERT_ID");
    header.push_back("EVAL_TIME");
    header.push_back("OBJECTIVE");

    for (int i = 0; i < m->numberOfBinaryVariables(); ++i)
        header.push_back(QString("BIN%1").arg(i));
    for (int i = 0; i < m->numberOfIntegerVariables(); ++i)
        header.push_back(QString("INT%1").arg(i));
    for (int i = 0; i < m->numberOfRealVariables(); ++i)
        header.push_back(QString("REA%1").arg(i));
}

void ResultsLogger::addEntry(Perturbation *p, Result *r, int evaluationTime)
{
    QStringList entry;
    entry.push_back(QString::number(p->getPerturbation_id()));
    entry.push_back(QString::number(evaluationTime));
    entry.push_back(QString::number(r->getResult()));

    for (int i = 0; i < p->getBinaryLength(); ++i)
        entry.push_back(QString::number(p->getBinaryVariables().at(i)));
    for (int i = 0; i < p->getIntegerLength(); ++i)
        entry.push_back(QString::number(p->getIntegerVariables().at(i)));
    for (int i = 0; i < p->getRealLength(); ++i)
        entry.push_back(QString::number(p->getRealVariables().at(i)));

    lines.push_back(entry);
}

void ResultsLogger::writeLog()
{
    std::cout << "Attempting to write results to: " << output_directory_path.toLatin1().constData() << std::endl;
    QFile file;
    QDir::setCurrent(output_directory_path);
    file.setFileName("results.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << header.join("\t") << "\n";
    for (int i = 0; i < lines.size(); ++i)
        out << lines.at(i).join("\t") << "\n";
}
