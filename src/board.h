#ifndef BOARD_H
#define BOARD_H

#include "def.h"
#include "position.h"
#include "pos_cal.h"
#include "types_and_constants.h"

inline PlayerColor OppstColor(PlayerColor color)
{
    static const PlayerColor T[2] = {1, 0};
    return T[color];
}



template <BoardLen BOARD_LEN>
class Board
{
public:
    Board() = default;
    virtual ~Board() {}
    DISALLOW_COPY_AND_ASSIGN(Board);
    virtual void Init();
    virtual void Copy(const Board<BOARD_LEN> &b);

    Point GetPoint(PointIndex index) const;
    Point GetPoint(const Position &pos) const;

    void SetPoint(PointIndex index, Point point);
    void SetPoint(const Position &pos, Point point);

    inline PosCalculator<BOARD_LEN> &GetPosClcltr() const {
        return PosCalculator<BOARD_LEN>::Ins();
    }

//#ifdef DTEST
    virtual void PRINT() const;
    static void TEST();
//#endif

private:
    Point points_[BLSq<BOARD_LEN>()];
};



#include "board-TLT.h"

//#ifdef DTEST
#include "board_TEST.h"
//#endif

#endif
