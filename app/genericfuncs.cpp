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

#include "genericfuncs.h"

#include <QPainter>

const QPixmap drawPixmapOnPixmap(int x, int y, const QPixmap& pixmapUnder, const QPixmap& pixmapOver)
{
    Q_ASSERT(pixmapUnder.width() >= pixmapOver.width() + x);
    Q_ASSERT(pixmapUnder.height() >= pixmapOver.height() + y);

    QPixmap combinedPixmap(pixmapUnder.width(), pixmapUnder.height());
    combinedPixmap.fill(Qt::transparent);

    QPainter painter(&combinedPixmap);

    painter.drawPixmap(0, 0, pixmapUnder);
    painter.drawPixmap(x, y, pixmapOver);

    return combinedPixmap;
}

const QPixmap drawTextOnPixmap(int x, int y, int w, int h, int flags, const QFont& font, const QColor& textColor, const QString& text, const QPixmap& pixmap)
{
    QPixmap combinedPixmap(pixmap.width(), pixmap.height());
    combinedPixmap.fill(Qt::transparent);

    QPainter painter(&combinedPixmap);

    painter.setPen(textColor);
    painter.setFont(font);
    painter.drawPixmap(0, 0, pixmap);
    painter.drawText(x, y, w, h, flags, text);

    return combinedPixmap;
}

const QPixmap genHorizontallyTiledPixmap(const QPixmap& pixmap, uint repeatTimes)
{
    QPixmap tiledPixmap(pixmap.width() * repeatTimes, pixmap.height());
    tiledPixmap.fill(Qt::transparent);

    QPainter painter(&tiledPixmap);

    for (uint i = 0; i < repeatTimes; i++)
        painter.drawPixmap(i * pixmap.width(), 0, pixmap);

    return tiledPixmap;
}

const QPixmap appendPixmapToPixmapHorizontally(const QPixmap& pixmap1, const QPixmap& pixmap2)
{
    QPixmap combinedPixmap(pixmap1.width() + pixmap2.width(),
                           qMax(pixmap1.height(), pixmap2.height()));
    combinedPixmap.fill(Qt::transparent);

    QPainter painter(&combinedPixmap);

    painter.drawPixmap(0, 0, pixmap1);
    painter.drawPixmap(pixmap1.width(), 0, pixmap2);

    return combinedPixmap;
}
