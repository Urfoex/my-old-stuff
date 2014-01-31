{-----------------------------------------------------------------------------
-                                   HAtaGo                                   -
------------------------------------------------------------------------------ 
-
- by:       BellersenM@googlemail.com
- License:  GPLv3
-   Copyright (C) 2011  Manuel Bellersen
-
-   This program is free software: you can redistribute it and/or modify
-   it under the terms of the GNU General Public License as published by
-   the Free Software Foundation, either version 3 of the License, or
-   (at your option) any later version.
-
-   This program is distributed in the hope that it will be useful,
-   but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-   GNU General Public License for more details.
-
-   You should have received a copy of the GNU General Public License
-   along with this program.  If not, see <http://www.gnu.org/licenses/>.
-
-
-
-----------------------------------------------------------------------------}

{-----------------------------------------------------------------------------
-   importing needed things
-----------------------------------------------------------------------------}
import Data.Map
import qualified Data.Map as Map
import Control.Monad
import Data.Array
import Data.Char
import Data.Maybe
import qualified Data.List as MyList
import System.IO
import qualified System.Random as Rand
import qualified GHC.Base as MyBase

{-----------------------------------------------------------------------------
-   some data-definition
-----------------------------------------------------------------------------}

{-| The board where to play on-}
data Board = Board { contents :: Map ( Int, Int) Color, next :: Color,
    lastMove :: Move }
    deriving Show

{-| A board to set checked fields-}
data CheckBoard = CheckBoard { checkCont :: Map ( Int, Int) Color}
    deriving (Show, Eq)

{-| A tree for the ki to create a "good" Move-}
data Tree = Tree {  children :: [ ( Move, Tree)],
                    board :: Board,
                    value :: Double }
    deriving Show

{-| Move made by player or ki-}
data Move = Move {  position :: ( Int, Int),
                    color :: Color }
    deriving Show

{-| Stones are just BLACK or WHITE-}
data Color = BLACK | WHITE
    deriving (Show, Eq)

{-| You can only WIN or LOSE-}
data Situation = WIN | LOSE
    deriving (Show, Eq)

{-| Maybe there is somewhere Free or everywhere is Unfree-}
data Freedom = Free | Unfree
    deriving (Show, Eq)

{-| Unfree + True -> own with 0 liberties
    Unfree + False -> border or other with >= 1 liberties
    Free + True -> other with 0 liberties
    Free + False -> free field or own with >= 1 liberties-}
data FreeErase = FreeErase { itsFreedom :: Freedom, wasTaken:: Bool}
    deriving (Show, Eq)    

{-| Number of liberties of a group and its Color and the CheckBoard where
        it was checked-}
data Group = Group { liberties :: Int, gcolor :: Color, 
    checkBoard :: CheckBoard}
    deriving (Show, Eq)

{-| Types of what white can be-}
data Playertype = KI | HUMAN
    deriving (Show, Eq)

{-----------------------------------------------------------------------------
-   functions    
-----------------------------------------------------------------------------}

{-| Starting to play with the setUp-}
main :: IO ()
main = do
    print "                                     HAtaGo"
    print "                      Copyright (C) 2011  Manuel Bellersen"
    print "                 This program comes with ABSOLUTELY NO WARRANTY."
    print "          This is free software, and you are welcome to redistribute it"
    print "                            under certain conditions."
    print " "
    print "Greetings."
    print "Of what type (HUMAN or KI) is the player who has to play white?"
    putStr "> "
    hFlush stdout
    _in <- getLine
    let choise = lowerString _in
    case choise of
        "human" -> play setUp HUMAN
        "ki"    -> play setUp KI 
        _       -> do
                print "Could not determine type. Choosing KI ..."
                play setUp KI

{-| Creates a rating for the Board-}
evaluate :: Board -> IO Double
evaluate _board = case checkSituation (lastMove _board) _board of
    Just WIN ->  return 1
    Just LOSE -> return (-1)
    Nothing -> liftM (\ _var -> fromIntegral(sum _var)/1000.0) 
        (mapM (\ f -> eva _board 100) [1 .. 1000])

{-| Recursive evalutationg until WIN/LOSE/Depth=0 
    returning 1 for WIN and 0 else-}
eva :: Board -> Int -> IO Int
eva _board _depth = if (length (following _board)) == 0 then return 0
        else getRan _board >>= caseKiOf _board _depth

{-| Getting a random number -}
getRan :: Board -> IO Int
getRan _board = Rand.getStdRandom ( Rand.randomR ( 0, (length (following _board) - 1)))

{-| Just extracted-}
caseKi :: Board -> Int -> Maybe Situation
caseKi _board _i = (kiPlay _board Move{ position = ((!!) 
            (following _board) _i), color = next _board})

{-| Just extracted-}
caseKiOf :: Board -> Int -> Int -> IO Int
caseKiOf _board _depth _i = case caseKi _board _i of
    Just WIN -> return 1
    Just LOSE -> return (-1)
    Nothing -> if _depth == 0 then return 0
            else eva (move Move{ position = (!!) (following _board) _i,
                    color = next _board} _board) (_depth - 1)

{-| Checking Situation on a Move made by KI-}
kiPlay :: Board -> Move -> Maybe Situation
kiPlay _board _move = checkSituation _move (move _move _board)

{-| Big array with all possible moves-}
myArray :: [(Int,Int)]
myArray = [(1,1),(2,1),(3,1),(4,1),(5,1),(6,1),(7,1),(8,1),(9,1),
    (1,2),(2,2),(3,2),(4,2),(5,2),(6,2),(7,2),(8,2),(9,2),
    (1,3),(2,3),(3,3),(4,3),(5,3),(6,3),(7,3),(8,3),(9,3),
    (1,4),(2,4),(3,4),(4,4),(5,4),(6,4),(7,4),(8,4),(9,4),
    (1,5),(2,5),(3,5),(4,5),(5,5),(6,5),(7,5),(8,5),(9,5),
    (1,6),(2,6),(3,6),(4,6),(5,6),(6,6),(7,6),(8,6),(9,6),
    (1,7),(2,7),(3,7),(4,7),(5,7),(6,7),(7,7),(8,7),(9,7),
    (1,8),(2,8),(3,8),(4,8),(5,8),(6,8),(7,8),(8,8),(9,8),
    (1,9),(2,9),(3,9),(4,9),(5,9),(6,9),(7,9),(8,9),(8,9)]

{-| Gets a list of possible Moves-}
following :: Board -> [(Int,Int)]
following _board = myArray MyList.\\ (keys (contents _board))

{-| Adds the Move to the Board-}
move :: Move -> Board -> Board
move _move _board = Board {
    contents = insert (position _move) (color _move) (contents _board) ,
        next = case color _move of
                BLACK -> WHITE
                WHITE -> BLACK ,
        lastMove = _move}

{-| Gets a Move from ki for the white player-}
ki :: Board -> IO (Maybe Move)
ki _board = liftM (\ _pos -> Just Move{ position = _pos, color = next _board})
    (kiii _board)

kiii :: Board -> IO (Int,Int)
kiii _board = do
    a <-listOfEval _board
    let max = maximum a
    print ("maximum: " ++ (show max))
    print ( MyList.elemIndices max a )
    print ( MyBase.map ((!!) (following _board)) (MyList.elemIndices max a))
    return $ (!!) (following _board) (fromJust 
            (MyList.elemIndex max a)) 

listOfEval :: Board -> IO [Double]
listOfEval _board = mapM  (\ b -> evaluate b) (MyBase.map (getBoard _board) 
        (following _board))

getBoard :: Board -> (Int,Int) -> Board
getBoard _board _pos = move Move{position=_pos, color=next _board} _board

{-| Debug -}
printEvalLeft :: [Double] -> Board -> IO ()
printEvalLeft _leva _board = print $ show $ zip _leva (following _board)

{-| Printing the hole board with inscriptions-}
printBoard :: Board -> IO ()
printBoard _board = do
    let xys = [1 .. 9]
    print [" ","abcdefghi"]
    forM_ (reverse xys) $ \ y ->
        print $ [(( listArray (1,9) ['1' .. '9']) Data.Array.! y)] :
        (forM xys (\ x -> [ getColor(Map.lookup  (x,y) (contents _board) )]))

{-| Tries to get in Move from a player from stdin-}
readPosition :: Color -> IO (Maybe Move)
readPosition _color = do
    putStr "> "
    hFlush stdout
    _in <- getLine
    case (lowerString _in) of
        "pass"    -> return ( Just (Move { position = (0,0), color = _color }))
        "give up" -> return Nothing
        x:y:rest  -> if rest == [] then do
            let (a,b) = transformPosition x y
            if a == 0 || b == 0 then readAgain _color
                else return (Just (Move { position = (a,b) , color = _color}))
            else readAgain _color
        _ -> readAgain _color

{-| Writing a failure message and calling readPosition-}
readAgain :: Color -> IO (Maybe Move)
readAgain _color = do
    print "Wrong input. Please try again."
    readPosition _color

{-| Transforms a Char-position into a Int-position-}
transformPosition :: Char -> Char -> (Int,Int)
transformPosition x y = ( 
    if isAlpha x then
        if ord x > 96 && ord x < 106 then ord x - 96
            else 0
        else 0
    ,
    if isDigit y then digitToInt y else 0
    )

{-| Converts a String to lower case-}
lowerString :: String -> String
lowerString _string = case _string of
    [] -> ""
    _  -> case (tail _string) of
            [] -> [toLower (head _string)]
            _  -> (toLower (head _string)) : (lowerString (tail _string))
        
{-| Converts a Maybe Color into a printable Char-}
getColor :: Maybe Color -> Char
getColor _color = case _color of
    Nothing     -> '.'
    Just BLACK  -> 'X'
    Just WHITE  -> 'O'

{-| Placing some start-stones on the board-}
setUp :: Board
setUp = Board { contents = 
-- 4 points in center    
    insert (5,5) BLACK 
    $insert (5,6) WHITE 
    $insert (4,6) BLACK 
    $insert (4,5) WHITE
-- right side
--     $insert (9,9) BLACK
--     $insert (9,8) BLACK
--     $insert (9,7) BLACK
--     $insert (9,5) BLACK
--     $insert (9,4) BLACK
--     $insert (9,3) BLACK
--     $insert (9,2) BLACK
--     $insert (9,1) BLACK
--     $insert (8,9) WHITE
--     $insert (8,8) WHITE
--     $insert (8,7) WHITE
--     $insert (8,5) WHITE
--     $insert (8,4) WHITE
--     $insert (8,3) WHITE
--     $insert (8,2) WHITE
--     $insert (8,1) WHITE
--     $insert (8,6) WHITE
-- center
--     $insert (4,4) WHITE
--     $insert (5,4) WHITE
--     $insert (6,4) WHITE
--     $insert (6,5) WHITE
--     $insert (5,7) WHITE
--     $insert (6,7) WHITE
--     $insert (7,7) WHITE
--     $insert (7,6) WHITE
-- down left
--     $insert (1,2) WHITE
--     $insert (2,1) WHITE
--     $insert (2,3) WHITE
--     $insert (1,4) WHITE
--     $insert (3,4) BLACK
--     $insert (4,4) BLACK
--     $insert (5,4) BLACK
--     $insert (6,4) BLACK
--     $insert (7,4) BLACK
--     $insert (4,1) WHITE
--     $insert (5,1) WHITE
--     $insert (6,1) WHITE
--     $insert (4,3) WHITE
--     $insert (5,3) WHITE
--     $insert (6,3) WHITE
--     $insert (4,2) WHITE
--     $insert (6,2) WHITE
--     $insert (3,1) BLACK
--     $insert (3,2) BLACK
--     $insert (3,3) BLACK
--     $insert (7,1) BLACK
--     $insert (7,2) BLACK
--     $insert (7,3) BLACK
     empty
    , next = BLACK,
    lastMove = Move { position = (0,0), color = WHITE}}

{-| Reads a Move from player or ki
    Calls doPlay-}
play :: Board -> Playertype -> IO ()
play _board _pt = do
    printBoard _board
    putStr "to play: " 
    print $ next _board
    case next _board of
        BLACK -> do
                _input <- readPosition BLACK
                printPosition _input
                doPlay _board _pt _input
        WHITE -> case _pt of
            KI -> do
--                 let _input = ki _board
                _input <- ki _board
                printPosition _input
                doPlay _board _pt _input
            HUMAN -> do
                _input <- readPosition WHITE
                printPosition _input
                doPlay _board _pt _input

{-| Printing message about Move-}
printPosition :: Maybe Move -> IO ()
printPosition _move = case _move of
    Nothing -> print ( "# Giving up." )
    Just (Move { position = (0,0) , color = _}) ->
        print ( "# " ++ show (color (fromJust _move)) ++ " passes" )
    _ -> print ("# " ++ show (color (fromJust _move)) ++ ": " ++
            ( show (position (fromJust _move)) ))

{-| Analysing Move and trying to set it on Board
    Calls play if no capture, give up or pass-}
doPlay :: Board -> Playertype -> Maybe Move -> IO ()
doPlay _board _pt _move = case _move of
    Nothing -> print ("Game Over. " ++ (show (next _board)) ++ " loses.")
    Just (Move { position = (0,0) , color = _}) -> 
        if ( position (lastMove _board) ) == (0,0) then
            print ("Game Over. Both passed. Draw.")
            else play (switchColor _board) _pt
    _ -> if (isPossibleMove (fromJust _move) _board) then do
            let _new_board = move (fromJust _move) _board
            case (checkSituation (fromJust _move) _new_board) of
                Nothing -> case (next _new_board) of
                    BLACK -> play _new_board _pt
                    WHITE -> play _new_board _pt
                Just WIN  -> printEnd _new_board (show 
                        (next _board)) "wins"
                Just LOSE -> printEnd _new_board (show 
                        (next _board)) "loses"
            else do 
                print "Wrong move. Please try again."
                play _board _pt
    
{-| Returns True if no stone a that place on Board-}
isPossibleMove :: Move -> Board -> Bool
isPossibleMove _move _board = notMember (position _move) (contents _board)

{-| Prints the appropriate ending message-}
printEnd :: Board -> String -> String -> IO ()
printEnd _board _name _situation = do
    printBoard _board
    print ("Game Over. " ++ _name ++ " " ++ _situation ++ ".")

{-| Converts the lookAround of Move into a Situation-}
checkSituation :: Move -> Board -> Maybe Situation
checkSituation _move _board = 
    case lookAround (position _move) _board of
        FreeErase { itsFreedom = Unfree, wasTaken = True} -> Just LOSE
        FreeErase { itsFreedom = Free, wasTaken = True} -> Just WIN
        FreeErase { itsFreedom = Free, wasTaken = False} -> Nothing
        _ -> Just LOSE

{-| This is lookAround with print-debug-output
    For direct useage and analysation-}
-- tryLook (x,y) _board = do
--     let cb = visitCheckBoard Move { position = (x,y), color = BLACK}
--     print (show cb)
--     let myc = fromJust( Map.lookup (x,y) (contents _board))
--     print (show myc)
--     let up = setColorAndCount (x, y-1) myc _board cb
--     print ("up: " ++ show up)
--     let freeUp = group2FreeErase myc up
--     print (show freeUp)
--     let right = setColorAndCount (x+1, y) myc _board cb
--     print ("right: " ++ show right)
--     let freeRight = group2FreeErase myc right 
--     print (show freeRight)
--     let down = setColorAndCount (x, y+1) myc _board cb
--     print ("down: " ++ show down)
--     let freeDown = group2FreeErase myc down
--     print (show freeDown)
--     let left = setColorAndCount (x-1, y) myc _board cb
--     print ("left: " ++ show left)
--     let freeLeft = group2FreeErase myc left
--     print (show freeLeft)
--     if checkWin freeUp || checkWin freeRight || checkWin freeDown || 
--         checkWin freeLeft then
--         print FreeErase { itsFreedom = Free, wasTaken = True} 
--         else if checkLose freeUp && checkLose freeRight && checkLose freeDown 
--             && checkLose freeLeft then
--                print FreeErase { itsFreedom = Unfree, wasTaken = True} 
--                else
--                    print FreeErase { itsFreedom = Free, wasTaken = False} 

{-| Checks Groups around give place
    Can return win and lose information-}
lookAround :: (Int, Int) -> Board -> FreeErase
lookAround (x,y) _board = do
    let cb = visitCheckBoard Move { position = (x,y), color = BLACK}
    let myc = fromJust (Map.lookup (x,y) (contents _board))
    let up = setColorAndCount (x, y-1) myc _board cb
    let freeUp = group2FreeErase myc up
    let right = setColorAndCount (x+1, y) myc _board cb
    let freeRight = group2FreeErase myc right 
    let down = setColorAndCount (x, y+1) myc _board cb
    let freeDown = group2FreeErase myc down
    let left = setColorAndCount (x-1, y) myc _board cb
    let freeLeft = group2FreeErase myc left
    if checkWin freeUp || checkWin freeRight || checkWin freeDown || 
        checkWin freeLeft then
        FreeErase { itsFreedom = Free, wasTaken = True} 
        else if checkLose freeUp && checkLose freeRight && checkLose freeDown 
            && checkLose freeLeft then
               FreeErase { itsFreedom = Unfree, wasTaken = True} 
               else
                   FreeErase { itsFreedom = Free, wasTaken = False} 

{-| Returns True if stone or group of other color would have 0 liberties-}
checkWin :: FreeErase -> Bool
checkWin _fe = _fe == FreeErase { itsFreedom = Free, wasTaken = True}

{-| Returns True if stone or group of own color would have 0 liberties-}
checkLose :: FreeErase -> Bool 
checkLose _fe = _fe == FreeErase { itsFreedom = Unfree, wasTaken = True} ||
    _fe == FreeErase { itsFreedom = Unfree, wasTaken = False}

{-| Transforms a Maybe Group into a FreeErase
    Depends on given Color-}
group2FreeErase :: Color -> Maybe Group -> FreeErase
group2FreeErase myc _mg = case _mg of
    Nothing -> FreeErase {itsFreedom = Unfree, wasTaken = False}
    Just Group { liberties = -1, gcolor = _, checkBoard = _} -> 
        FreeErase { itsFreedom = Free, wasTaken = False}
    Just Group { liberties = 0, gcolor = _, checkBoard = _} -> 
        if gcolor (fromJust _mg) == myc then
            FreeErase { itsFreedom = Unfree, wasTaken = True}
            else FreeErase { itsFreedom = Free, wasTaken = True}
    Just Group { liberties = _, gcolor = _, checkBoard = _} -> 
        if gcolor (fromJust _mg) == myc then
            FreeErase { itsFreedom = Free, wasTaken = False}
            else FreeErase { itsFreedom = Unfree, wasTaken = False}

{-| Checks if position is on board has stone there
    Can call countFreedom-}
setColorAndCount :: (Int, Int) -> Color -> Board -> CheckBoard -> Maybe Group
setColorAndCount (x,y) _color _board _cb = 
    if (Map.lookup (x,y) (contents _board) == Nothing) && 
        ( x > 0 && x < 10 && y > 0 && y < 10) then
        Just Group { liberties = 1, gcolor = _color, checkBoard = 
             CheckBoard { checkCont = insert (x,y) _color ( checkCont _cb)}}
        else
            countFreedom (x,y) (fromJust (Map.lookup (x,y) (
                            contents _board))) _board _cb

{-| Trying to create a Group
    Returns Nothing if out of size of board or position already in CheckBoard
    Can call countFour-}
countFreedom :: (Int, Int) -> Color -> Board -> CheckBoard -> Maybe Group
countFreedom (x,y) _color _board _cb=
    if x == 0 || x == 10 || y == 0 || y == 10 then Nothing
        else if member (x,y) (checkCont _cb) then Nothing
                else do
                    let _fcolor = case Map.lookup (x,y) (contents _board) of
                            Nothing -> _color
                            Just BLACK -> BLACK
                            Just WHITE -> WHITE
                    let _new_cb = CheckBoard { checkCont = insert (x,y) _fcolor
                        (checkCont _cb)}
                    if Map.lookup (x,y) (contents _board) == Nothing then
                        Just Group { liberties = 1, gcolor = _color, 
                            checkBoard = _new_cb}
                        else if Map.lookup (x,y) (contents _board) == 
                            Just _color then 
                                countFour (x,y) _color _board _new_cb
                                else Just Group { liberties = 0, gcolor =
                                    (fromJust (Map.lookup (x,y) (
                                    contents _board))), checkBoard = _new_cb}

{-| Creating a Group of surrounding fields-}
countFour :: (Int,Int) -> Color -> Board -> CheckBoard -> Maybe Group
countFour (x,y) _color _board _cb = do
    let up = countFreedom (x, y-1) _color _board _cb
    let upcb = if up == Nothing then _cb else checkBoard (fromJust up)
    let right = countFreedom (x+1, y) _color _board upcb
    let rightcb = if right == Nothing then upcb else checkBoard (
            fromJust right)
    let down = countFreedom (x, y+1) _color _board rightcb
    let downcb = if down == Nothing then rightcb else checkBoard (
            fromJust down)
    let left = countFreedom (x-1, y) _color _board downcb
    let leftcb = if left == Nothing then downcb else checkBoard (fromJust left)
    Just Group { liberties = getNumber up + getNumber right + getNumber down + 
        getNumber left , gcolor = _color, checkBoard = leftcb}

{-| Returns the number of liberties from Maybe Group
    Nothing counts as 0 liberties-}
getNumber :: Maybe Group -> Int
getNumber _mg = case _mg of
    Nothing -> 0
    _ -> liberties (fromJust _mg)

{-| Creating a CheckBoard with Move set on it-}
visitCheckBoard :: Move -> CheckBoard
visitCheckBoard _move = CheckBoard { 
    checkCont = insert (position _move) (color _move) empty }

{-| Changing next and lastMove from Board according to fit a PASS-}
switchColor :: Board -> Board
switchColor _board = case next _board of
    BLACK -> Board { contents = contents _board, next = WHITE, 
        lastMove = Move { position = (0,0), color = BLACK}}
    WHITE -> Board { contents = contents _board, next = BLACK,
        lastMove = Move { position = (0,0), color = WHITE}}
