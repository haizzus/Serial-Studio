/*
 * Copyright (c) 2020-2022 Alex Spataru <https://github.com/alex-spataru>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

#include <QAction>
#include <QObject>

namespace Misc
{
/**
 * @brief The MacExtras class
 *
 * The @c MacExtras class implements specialized functions that are used only in macOS
 * targets. For the moment, this class implements the code necessary to interact with the
 * touchbar display for some MacBook models.
 */
class MacExtras : public QObject
{
    Q_OBJECT

Q_SIGNALS:
    void setupClicked();
    void connectClicked();
    void consoleClicked();
    void dashboardClicked();

private:
    explicit MacExtras();
    MacExtras(MacExtras &&) = delete;
    MacExtras(const MacExtras &) = delete;
    MacExtras &operator=(MacExtras &&) = delete;
    MacExtras &operator=(const MacExtras &) = delete;

public:
    static MacExtras &instance();

public Q_SLOTS:
    void setSetupChecked(const bool checked);
    void setConsoleChecked(const bool checked);
    void setDashboardChecked(const bool checked);
    void setDashboardEnabled(const bool enabled);

private Q_SLOTS:
    void updateButtonText();

private:
    QAction m_setupAction;
    QAction m_consoleAction;
    QAction m_dashboardAction;
};
}
