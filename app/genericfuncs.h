/*
  Copyright (C) 2017 by Vangelis Tasoulas <vangelis@tasoulas.net>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of
  the License or (at your option) version 3 or any later version
  accepted by the membership of KDE e.V. (or its successor appro-
  ved by the membership of KDE e.V.), which shall act as a proxy
  defined in Section 14 of version 3 of the license.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see http://www.gnu.org/licenses/.
*/

#ifndef GENERICFUNCS_H
#define GENERICFUNCS_H

#include <QPixmap>
#include <QDebug>

const QPixmap drawPixmapOnPixmap(int x, int y, const QPixmap& pixmapUnder, const QPixmap& pixmapOver);
const QPixmap drawTextOnPixmap(int x, int y, int w, int h, int flags, const QFont& font, const QColor& textColor, const QString& text, const QPixmap& pixmap);
const QPixmap genHorizontallyTiledPixmap(const QPixmap& pixmap, uint repeatTimes);
const QPixmap appendPixmapToPixmapHorizontally(const QPixmap& pixmap1, const QPixmap& pixmap2);

#endif // GENERICFUNCS_H
