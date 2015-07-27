// This file is part of RSS Guard.
//
// Copyright (C) 2011-2015 by Martin Rotter <rotter.martinos@gmail.com>
//
// RSS Guard is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RSS Guard is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RSS Guard. If not, see <http://www.gnu.org/licenses/>.

#ifndef FEEDSMODELCATEGORY_H
#define FEEDSMODELCATEGORY_H

#include "core/rootitem.h"

#include <QSqlRecord>
#include <QCoreApplication>


class FeedsModel;

// Base class for all categories contained in FeedsModel.
// NOTE: This class should be derived to create PARTICULAR category types.
// NOTE: This class should not be instantiated directly.
class Category : public RootItem {
    Q_DECLARE_TR_FUNCTIONS(Category)

  public:
    // Constructors and destructors
    explicit Category(RootItem *parent_item = NULL);
    explicit Category(const Category &other);
    explicit Category(const QSqlRecord &record);
    virtual ~Category();

    // Returns the actual data representation of standard category.
    QVariant data(int column, int role) const;

    // Removes category and all its children from persistent
    // database.
    bool removeItself();

    bool addItself(RootItem *parent);
    bool editItself(Category *new_category_data);

  private:
    void init();
};

#endif // FEEDSMODELCLASSICCATEGORY_H