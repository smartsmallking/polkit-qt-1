/*
    This file is part of the Polkit-qt project
    SPDX-FileCopyrightText: 2009 Jaroslav Reznik <jreznik@redhat.com>
    SPDX-FileCopyrightText: 2010 Dario Freddi <drf@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef POLKITQT1_ACTION_DESCRIPTION_H
#define POLKITQT1_ACTION_DESCRIPTION_H

#include "polkitqt1-export.h"

#include <QtCore/QList>
#include <QtCore/QMetaType>
#include <QtCore/QSharedData>

typedef struct _PolkitActionDescription PolkitActionDescription;

namespace PolkitQt1
{
/**
 * \class ActionDescription polkitqt1-actiondescription.h ActionDescription
 * \author Jaroslav Reznik <jreznik@redhat.com>
 * \author Dario Freddi <drf@kde.org>
 *
 * \brief Class used to encapsulate a registered action.
 */
class POLKITQT1_EXPORT ActionDescription
{
public:
    enum ImplicitAuthorization {
        /** Unknown whether the subject is authorized, never returned in any public API. **/
        Unknown = -1,
        /** Subject is not authorized. **/
        NotAuthorized = 0,
        /** Authentication is required. **/
        AuthenticationRequired = 1,
        /** Authentication as an administrator is required. **/
        AdministratorAuthenticationRequired = 2,
        /** Authentication is required. If the authorization is obtained, it is retained. **/
        AuthenticationRequiredRetained = 3,
        /** Authentication as an administrator is required. If the authorization is obtained, it is retained. **/
        AdministratorAuthenticationRequiredRetained = 4,
        /** The subject is authorized. **/
        Authorized = 5
    };

    typedef QList< ActionDescription > List;

    ActionDescription();
    /**
     * \brief Constructor of ActionDescription object from PolkitActionDescription
     *
     * \warning Use this only if you are completely aware of what are you doing!
     *
     * \param actionDesciption PolkitActionDescription
     */
    explicit ActionDescription(PolkitActionDescription *actionDescription);
    ActionDescription(const ActionDescription &other);
    ~ActionDescription();

    ActionDescription &operator=(const ActionDescription &other);

    /**
     * \brief Gets the action id for ActionDescription
     *
     * \return id of the action
     */
    QString actionId() const;

    /**
     * \brief Gets the description used for ActionDescription
     *
     * \return description of the action
     */
    QString description() const;

    /**
     * \brief Gets the message used for ActionDescription
     *
     * \return action message
     */
    QString message() const;

    /**
     * \brief Gets the vendor name for ActionDescription, if any
     *
     * \return vendor name
     */
    QString vendorName() const;

    /**
     * \brief Gets the vendor URL for ActionDescription, if any
     *
     * \return vendor URL or empty QString if there is no vendor URL
     */
    QString vendorUrl() const;

    /**
     * \brief Gets the icon name for ActionDescription, if any
     *
     * \return icon name or empty QString if there is no icon
     */
    QString iconName() const;

    /**
     * \brief Gets the implicit authorization for ActionDescription used for any subject
     *
     * \return A value from ImplicitAuthorization enumeration
     */
    ActionDescription::ImplicitAuthorization implicitAny() const;

    /**
     * \brief Gets the implicit authorization for ActionDescription used for subjects in inactive session on a local console
     *
     * \return A value from ImplicitAuthorization enumeration
     */
    ActionDescription::ImplicitAuthorization implicitInactive() const;

    /**
     * \brief Gets the implicit authorization for ActionDescription used for subjects in active session on a local console
     *
     * \return A value from ImplicitAuthorization enumeration
     */
    ActionDescription::ImplicitAuthorization implicitActive() const;

private:
    class Data;
    QSharedDataPointer< Data > d;
};
}

Q_DECLARE_METATYPE(PolkitQt1::ActionDescription::List)

#endif //POLKIT_QT_ACTION_DESCRIPTION_H
