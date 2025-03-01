/*
    This file is part of the Polkit-qt project
    SPDX-FileCopyrightText: 2009 Dario Freddi <drf@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef POLKITQT1_GUI_ACTIONBUTTONS_H
#define POLKITQT1_GUI_ACTIONBUTTONS_H

#include "polkitqt1-gui-actionbutton.h"

namespace PolkitQt1
{

namespace Gui
{

class ActionButtonsPrivate;
/**
 * \class ActionButtons polkitqt1-gui-actionbuttons.h ActionButtons
 * \author Dario Freddi <drf@kde.org>
 *
 * \brief Class used to hold and update a list of QAbstractButtons
 *
 * This class is a convenience wrapper around ActionButton that lets
 * you associate an undefined number of QAbstractButtons with a single
 * action. Every button will be updated accordingly upon action's properties
 * changes.
 *
 * \see ActionButton
 */
class ActionButtons : public ActionButton
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(ActionButtons)
    Q_DISABLE_COPY(ActionButtons)

public:
    /**
     * Constructs a new ActionButton. You need to pass this
     * constructor an existing list of QAbstractButtons, whose properties
     * will be modified according to the underlying Action
     * object. As ActionButtons inherits from Action, you can
     * define your buttons' behavior right through this wrapper.
     *
     * \see Action
     *
     * \param buttons the QAbstractButton to associate to this ActionButton
     * \param actionId the action Id to create the underlying Action
     * \param parent the parent object
     */
    explicit ActionButtons(const QList<QAbstractButton *> &buttons, const QString &actionId = QString(), QObject *parent = nullptr);
    virtual ~ActionButtons();

    /**
     * Sets a list of buttons associated to the underlying action.
     *
     * \note If you are calling this function, you're probably
     *       changing the buttons list the action is referring to. If this
     *       is the case, please note that Polkit-Qt does not handle
     *       the previous buttons' memory, so you should take care of
     *       deleting them yourself (if needed). You can retrieve it by
     *       using buttons()
     *
     * \see buttons
     *
     * \param buttons the new buttons associated with the underlying action
     */
    void setButtons(const QList<QAbstractButton *> &buttons);

    /**
     * Returns the current buttons list
     *
     * \return the buttons currently associated with the underlying action
     */
    QList<QAbstractButton *> buttons() const;

    /**
     * Adds a button to the current button list. The button's properties
     * will be updated according to the action upon adding.
     *
     * \param button the button to add
     */
    void addButton(QAbstractButton *button);

    /**
     * Removes a button from the current list. Please note that Polkit-Qt
     * does not handle the removed button's memory, so you should take care of
     * deleting it yourself (if needed).
     *
     * \param button the button to remove
     */
    void removeButton(QAbstractButton *button);
};

}

}

#endif
