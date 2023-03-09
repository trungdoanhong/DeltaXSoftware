#include "GcodeHighlighter.h"


GCodeHighlighter::GCodeHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    QTextCharFormat gcodeFormat;
    gcodeFormat.setForeground(Qt::black);
//    gcodeFormat.setBackground(Qt::yellow);
    gcodeFormat.setFontWeight(QFont::Bold);
    QRegularExpression gcodeRegex("[Gg]\\d{1,3}\\b");
    highlightRule rule = {gcodeRegex, gcodeFormat};
    highlightRules.append(rule);

    QTextCharFormat mcodeFormat;
    mcodeFormat.setForeground(Qt::black);
    mcodeFormat.setFontWeight(QFont::Bold);
    QRegularExpression mcodeRegex("[Mm]\\d{1,3}\\b");
    rule = {mcodeRegex, mcodeFormat};
    highlightRules.append(rule);

    QTextCharFormat commentFormat;
    commentFormat.setForeground(Qt::darkGreen);
    commentFormat.setFontItalic(true);
    highlightRules.append({QRegularExpression(";.*"), commentFormat});

    QTextCharFormat lineNumberFormat;
    lineNumberFormat.setForeground(QColor(Qt::gray));
    QRegularExpression numberRegex("^N\\d+");
    rule = {numberRegex, lineNumberFormat};
    highlightRules.append(rule);

    QTextCharFormat gotoFormat;
    gotoFormat.setForeground(Qt::blue);
    gotoFormat.setFontWeight(QFont::Bold);
    QRegularExpression gotoRegex("\\bGOTO\\b");
    rule = {gotoRegex, gotoFormat};
    highlightRules.append(rule);

    QTextCharFormat ifthenFormat;
    ifthenFormat.setForeground(Qt::blue);
    ifthenFormat.setFontWeight(QFont::Bold);
    QRegularExpression ifRegex("\\bIF\\b|\\bTHEN\\b");
    rule = {ifRegex, ifthenFormat};
    highlightRules.append(rule);

    QTextCharFormat format;
    format.setFontItalic(true);
    QRegularExpression pattern("#\\w+");
    rule = {pattern, format};
    highlightRules.append(rule);
}

void GCodeHighlighter::highlightBlock(const QString &text)
{
    for (const highlightRule &rule : qAsConst(highlightRules)) {
        QRegularExpressionMatchIterator i = rule.pattern.globalMatch(text);
        while (i.hasNext()) {
            QRegularExpressionMatch match = i.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}
