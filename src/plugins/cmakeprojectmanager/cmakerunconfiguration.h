/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include <projectexplorer/runnables.h>

namespace CMakeProjectManager {
namespace Internal {

class CMakeRunConfiguration : public ProjectExplorer::RunConfiguration
{
    Q_OBJECT

public:
    explicit CMakeRunConfiguration(ProjectExplorer::Target *target);

    QString buildSystemTarget() const final { return m_buildSystemTarget; }

private:
    ProjectExplorer::Runnable runnable() const override;
    QWidget *createConfigurationWidget() override;

    QVariantMap toMap() const override;
    QString disabledReason() const override;

    Utils::OutputFormatter *createOutputFormatter() const final;

    bool fromMap(const QVariantMap &map) override;
    void doAdditionalSetup(const ProjectExplorer::RunConfigurationCreationInfo &) override;
    bool isBuildTargetValid() const;
    void updateTargetInformation();

    void updateEnabledState() final;
    QString extraId() const final;

    QString m_buildSystemTarget;
    QString m_title;
};

class CMakeRunConfigurationFactory : public ProjectExplorer::RunConfigurationFactory
{
    Q_OBJECT

public:
    CMakeRunConfigurationFactory();
};

} // namespace Internal
} // namespace CMakeProjectManager
