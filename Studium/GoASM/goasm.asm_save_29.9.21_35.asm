;=============================================================================;
;  GoASM                                                                      ;
; =======                                                                     ;
;                                                                             ;
; This is a two-player game based on the board-game Go.                       ;
; One player is white - the other black. Alternately each player places its   ;
; stone on the points on the board.                        ;
;                                                                             ;
; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = ;
; Made by:      Manuel Bellersen                                              ;
;  Matrikel:    46958                                                         ;
;  E-Mail:      manuel.bellersen@stud.htwk-leipzig.de                         ;
;  Licens:      GPLv3 or later                                                ;
;=============================================================================;
    .model small
    .486
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;  Constants
; ~~~~~~~~~~~
    esc_code = 1Bh              ;=> Codes of ASCII ESC,
    b_code   = 62h              ;   B,
    w_code   = 77h              ;   W,
    o_code   = 6Fh              ;   O,
    CR = 13                     ;   Carriage Return
    LF = 10                     ;   and Line Feed                           <=|
    video_seg  = 0A000h         ; Video-Segment
    board_size = 12             ; Size of the board (square) -> 12x12
    field_size = 16             ; Size of a graphical field
    win_width  = 320            ; Width of the dos-window
    win_height = 200            ; Height of the dos-window
    next_y = board_size         ; Number of fields till next y        
    next_x = 1                  ;              and till next x
    BLACK   = 0                 ;=> Symbolic constants for BLACK,
    WHITE   = 1                 ;   WHITE,
    TRUE    = 0                 ;   TRUE,
    FALSE   = 1                 ;   FALSE,
    FREE    = 0                 ;   FREE,
    UNFREE  = 1                 ;   UNFREE
    ALLFOUR = 4                 ;   and ALLFOUR (meaning all 4 directions)  <=|
    SGF_MAX = 256               ; Size of buffer to store placed stones for SGF
    S1         = 1000           ; One second is 1000ms
    MS55       = 55             ; Timer is called every 55ms
    SOUNDMAX   = 2              ; Sound is played maximal 2*55ms
    SOUND_HIGH = 00Bh           ; 16bit note to play ( G on 4th octave, 392Hz)
    SOUND_LOW  = 0E3h           ;


    .data
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;  Variables
; ~~~~~~~~~~~
    COUNT       DW 0h           ; Counting number of captured stones of a ERASE
    PointsBlack DW 0h           ; Holding number of captured stones of BLACK
    PointsWhite DW 0h           ;                                  and WHITE
    OldISRcs    DW 0h           ; Holding CS and
    OldISRbx    DW 0h           ;         BX of old ISR
    TimeBlack   DW 0h           ; Counter of seconds for BLACK
    TimeWhite   DW 0h           ;                    and WHITE
    TimeCounterBlack DW 0h      ; Counter of ms for BLACK
    TimeCounterWhite DW 0h      ;               and WHITE
    TimeSound   DW 0h           ; Counter for how long to hear the *beep*
    SOUND_OFF   DB 0h           ; Status of sound
    KISAVE      DW 0h           ; Saving overhead of random number 
    SGF_FID     DW 0h              ; Pointer to file to save sgf-data
    SGFPATH     DB "myGoASM.sgf",0 ; Path to store file
    SGFERRORMSG DB "Could not create myGoASM.sgf","$"    ; FAIL and
    SGFOKMSG    DB "Saved your game at myGoASM.sgf.","$" ; OK message
    SGFDATACOLOR DW SGF_MAX DUP (0) ;=> Place to save the color,
    SGFDATAX DB SGF_MAX DUP (0)     ;   the X
    SGFDATAY DB SGF_MAX DUP (0)     ;   and Y coordinates for the sgf-file
    SGFNUMBER   DW 0000h            ; Number of free field to save next stone
    SGFRUNNER   DW 0000h            ; Running up to number of last field
    SGFSIGNS DB "abcdefghijkl","$"  ;=> Characters to use in SGF-file for X,Y,
    SGFB     DB "B","$"             ;   player BLACK,
    SGFW     DB "W","$"             ;   player WHITE,
    SGFBRACKETOPEN  DB "(","$"      ;   start,
    SGFBRACKETCLOSE DB ")","$"      ;   end,
    SGFBOXOPEN      DB "[","$"      ;   coordinate-start,
    SGFBOXCLOSE     DB "]","$"      ;   coordinate-end,
    SGFSEMICOLON    DB ";","$"      ;   group-end and 
    SGFEXTRA   DB ";AP[GoASM:1.0]GM[1]SZ[12]","$" ; some static information
    BOARD      DW 144 DUP (0000h) ; The board where to play on (current  12x12)
    CHECKBOARD DB 144 DUP (0000h) ; Extra virtual board to set checked stones
    PLACED     DB 00h             ; Was stone placed: 0 OK    -- else Not Ok
    NextPlayer DB 00h             ; Who is next  : 0 BLACK -- else WHITE
    AROUND     DB 00h             ; Is around ok : 0 OK    -- else Not Ok
    LOOK       DB 00h             ; Look, is free: 0 Free  -- else not free
    COVAR      DB 00h             ; Is direction free: 0 Free  -- else not free
    YVAR       DW 00h             ; For restoring the Y value
    TEN           DB 10      ; "Constant" to dived through to get single values
    StartXPoints  DB 0h      ;=> Startpoints for captured points for X and
    StartYPoints  DB 0h      ;   Y and for
    StartXTimes   DB 0h      ;   time used for X and
    StartYTimes   DB 0h      ;   Y
    MYCOLOR      DW 0000h    ; Color of stone next to where to placed to
    OldMouseInt  DW 0000h    ; Saving old mouse routine
    OldMouseMask DW 0000h    ;    and old mouse mask
    ; Following are the BLACK and WHITE stones and the empty field
    BufferBlack DB field_size DUP (185, 185, 185, 185, 185, 185, 000, 000, 000, 000, 185, 185, 185, 185, 185, 185)
                DB field_size DUP (185, 185, 185, 185, 000, 000, 000, 000, 000, 000, 000, 000, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 185, 185, 185) 
                DB field_size DUP (185, 185, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 185, 185) 
                DB field_size DUP (185, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 185) 
                DB field_size DUP (185, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 185) 
                DB field_size DUP (000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000) 
                DB field_size DUP (000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000) 
                DB field_size DUP (000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000) 
                DB field_size DUP (000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000) 
                DB field_size DUP (185, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 185) 
                DB field_size DUP (185, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 185) 
                DB field_size DUP (185, 185, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 185, 185) 
                DB field_size DUP (185, 185, 185, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 000, 000, 000, 000, 000, 000, 000, 000, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 000, 000, 000, 000, 185, 185, 185, 185, 185, 185) 
    BufferWhite DB field_size DUP (185, 185, 185, 185, 185, 185, 015, 015, 015, 015, 185, 185, 185, 185, 185, 185)  
                DB field_size DUP (185, 185, 185, 185, 015, 015, 015, 015, 015, 015, 015, 015, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 185, 185, 185) 
                DB field_size DUP (185, 185, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 185, 185) 
                DB field_size DUP (185, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 185) 
                DB field_size DUP (185, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 185) 
                DB field_size DUP (015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015) 
                DB field_size DUP (015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015) 
                DB field_size DUP (015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015) 
                DB field_size DUP (015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015) 
                DB field_size DUP (185, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 185) 
                DB field_size DUP (185, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 185) 
                DB field_size DUP (185, 185, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 185, 185) 
                DB field_size DUP (185, 185, 185, 015, 015, 015, 015, 015, 015, 015, 015, 015, 015, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 015, 015, 015, 015, 015, 015, 015, 015, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 015, 015, 015, 015, 185, 185, 185, 185, 185, 185) 
    BufferField DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185)  
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 000, 015, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 015, 000, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
                DB field_size DUP (185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185) 
    Cursor   DW 1111111111111111b   ;=> This will be how the mousecursor will
             DW 1111000000011111b   ;   look like
             DW 1110000000000111b   ;   (first layer)
             DW 1100000000000011b
             DW 1000000000000011b
             DW 1000000000000001b
             DW 1000000000000001b
             DW 1000000000000001b
             DW 1000000000000001b
             DW 1000000000000001b
             DW 1000000000000001b
             DW 1100000000000001b
             DW 1100000000000001b
             DW 1110000000000011b
             DW 1111100000000111b
             DW 1111111111111111b   ;<=|
             DW 0000000000000000b   ;=> (second layer)
             DW 0000111100000000b
             DW 0001110000000000b
             DW 0011100001000000b
             DW 0111100011100000b
             DW 0111100001000000b
             DW 0111110000000000b
             DW 0111111000000000b
             DW 0111111110000000b
             DW 0111111111100000b
             DW 0111110011110000b
             DW 0011100001110000b
             DW 0011110011110000b
             DW 0001111111100000b
             DW 0000011110000000b
             DW 0000000000000000b   ;<=|
    BufferHUD DB CR, LF,"                                        "      ; This
              DB CR, LF,"                              GoASM     "      ; is
              DB CR, LF,"                                        "      ; the
              DB CR, LF,"                         Captured BLACK "      ; HUD
              DB CR, LF,"                                      0 "      
              DB CR, LF,"                                        "
              DB CR, LF,"                         Captured WHITE "
              DB CR, LF,"                                      0 "
              DB CR, LF,"                                        "
              DB CR, LF,"                         Time           "
              DB CR, LF,"                          B:          0 "
              DB CR, LF,"                          W:          0 "
              DB CR, LF,"                         Pass       Exit", "$"
    ; The next one is the message at the end of the game
    GoodBye DB CR, LF, "     _  _  _                          _          _  _  _  _    _           _   "
            DB CR, LF, "  _ (_)(_)(_) _                     _(_)_      _(_)(_)(_)(_)_ (_) _     _ (_)  " 
            DB CR, LF, " (_)         (_)    _  _  _       _(_) (_)_   (_)          (_)(_)(_)   (_)(_)  " 
            DB CR, LF, " (_)    _  _  _  _ (_)(_)(_) _  _(_)     (_)_ (_)_  _  _  _   (_) (_)_(_) (_)  " 
            DB CR, LF, " (_)   (_)(_)(_)(_)         (_)(_) _  _  _ (_)  (_)(_)(_)(_)_ (_)   (_)   (_)  " 
            DB CR, LF, " (_)         (_)(_)         (_)(_)(_)(_)(_)(_) _           (_)(_)         (_)  " 
            DB CR, LF, " (_) _  _  _ (_)(_) _  _  _ (_)(_)         (_)(_)_  _  _  _(_)(_)         (_)  " 
            DB CR, LF, "    (_)(_)(_)(_)   (_)(_)(_)   (_)         (_)  (_)(_)(_)(_)  (_)         (_)  " 
            DB CR, LF, "                                                                               " 
            DB CR, LF, " " 
            DB CR, LF, "          _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ " 
            DB CR, LF, "         (_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)" 
            DB CR, LF, "         (_)                                                      (_)" 
            DB CR, LF, "         (_)   Made by  Manuel Bellersen                          (_)" 
            DB CR, LF, "         (_)   E-Mail   manuel.bellersen@stud.htwk-leipzig.de     (_)" 
            DB CR, LF, "         (_)   Release  english version                           (_)" 
            DB CR, LF, "         (_)   Date     10/01/2010                                (_)" 
            DB CR, LF, "         (_)   Files    01/01                                     (_)" 
            DB CR, LF, "         (_)   Licens   GPLv3 or later                            (_)"
            DB CR, LF, "         (_) _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ (_)" 
            DB CR, LF, "         (_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)" 
            DB CR, LF, " " 
            DB CR, LF, "               ", "$"
    .stack    8000h             ; Stack is set to 32K, hope this is enough
    .code
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;  Code
; ~~~~~~
GoASM  proc                     ;--------------------------
    xor ax, ax                  ; Let's start the program! 
    mov ax, @DATA               ;--------------------------
    mov ds, ax                  ;=> Loading ds with DATA
    mov ax, video_seg           ;
    mov es, ax                  ;       and es with VIDEO
    mov ax, 13h                 ;=> Setting video-mode 13h
    int 10h                     ;   (640 x 480 x 16)
    lea dx, BufferHUD           ;=> Showing text-hud on screen 
    mov ah, 09h                 ;
    int 21h                     ;
    call DRAWBOARD              ; Drawing the board
    call SETMOUSE               ; Setting up the mouse
;    call SETTIMER               ; Setting up the timer
KeyCode: xor ah, ah             ;=> Query key-code 
         int 16h                ;   <ESC> to quit  
         cmp al, esc_code       ;   <B>   to set a BLACK stone
         je GoASM_END           ;   <W>   to set a WHITE stone
         cmp al, b_code         ;   <O>   to set a stone of current player
         je KeyBlack
         cmp al, w_code
         je KeyWhite
         cmp al, o_code
         je KeyKIMove
         jmp KeyCode
KeyBlack: cmp NextPlayer, WHITE ;=> Only if BLACK has pressed <B> the stone 
          je KeyCode            ;   will appear
          jmp KeyKIMove
KeyWhite: cmp NextPlayer, BLACK ;=> Only if WHITE has pressed <W> the stone
          je KeyCode            ;   will appear
KeyKIMove: call KIMOVE          ;=> Try to set a stone at a random place
           jmp KeyCode
GoASM_END: call UNSETMOUSE      ; Reset the mouse
;           call UNSETTIMER      ; Reset the interrupt           
           mov ax, 3            ;=> Setting standard video-mode 3h
           int 10h              ;   (80 x 25)
           lea dx, GoodBye      ;=> Showing endmessage on screen
           mov ah, 09h          ;
           int 21h              ; 
           call SAVESGF         ; Save the sgf-file
           mov ah, 4Ch          ;=> Going back to DOS 
           int 21h              ; 
           ret
GoASM endp
SETTIMER proc             ;-----------------------------------------------------
    cli                   ; Setting up the timer interrupt to use TIMER
    mov ah, 35h           ;-----------------------------------------------------
    mov al, 1Ch           ;
    int 21h               ; Get the current interrupt handler
    push es
    pop ax
    mov OldISRcs, ax      ; Save code-segment and
    mov OldISRbx, bx      ; function of used interrupt handler 
    push cs
    pop ds
    mov dx, OFFSET TIMER
    mov ah, 25h
    mov al, 1Ch
    int 21h               ; Set own TIMER as interrupt handler
    sti
    push @DATA            ;=> Restore 
    pop ds                ;   data
    push video_seg        ;   and 
    pop es                ;   extended segment                               <=|
    ret
SETTIMER endp
UNSETTIMER proc           ;-----------------------------------------------------
    push ds               ; Setting back to the previous used interrupt handler                         
    cli                   ;-----------------------------------------------------
    mov dx, OldISRbx      
    push OldISRcs
    pop ds
    mov ah, 25h
    mov al, 1Ch
    int 21h
    sti
    pop ds
    ret
UNSETTIMER endp
SAVESGF proc                    ;-----------------------------------------------
    push @DATA                  ; Create the SGF-file and insert data
    pop ds                      ;-----------------------------------------------
    mov dx, OFFSET SGFPATH      ;=> Try to delete the file
    xor cx, cx
    mov ax, 4100h                
    int 21h                     ;<=| 
    mov dx, OFFSET SGFPATH      ;=> Try to create a new file
    mov ax, 3C00h
    xor cx, cx
    int 21h                     ;<=| 
    jc SGF_ERROR                ; Check if an error occured
    mov SGF_FID, ax             ; Save the FileID
    mov dx, OFFSET SGFBRACKETOPEN   ;=> Write starting-bracket 
    call WRITECHAR                  ;
    mov dx, OFFSET SGFEXTRA     ;=> Write some extra information
    mov ax, 4000h
    mov bx, SGF_FID
    mov cx, 25 
    int 21h                     ;<=|
    call WRITESGF               ; Write data of placed stones
    mov dx, OFFSET SGFBRACKETCLOSE  ;=> Write the closing-bracket
    call WRITECHAR                  ;
    jmp SGF_OK
SGF_ERROR: mov dx, OFFSET SGFERRORMSG  ; Load FAIL-message
           jmp SGF_SHOWMSG             
SGF_OK: mov bx, SGF_FID         ;=> Close the open file
        mov ax, 3E00h               
        int 21h                 ;<=|
        mov dx, OFFSET SGFOKMSG         ; Load OK-Message
SGF_SHOWMSG: mov ax, 900h               ;=> Show the message
             int 21h                    ; 
SGF_END: ret
SAVESGF endp
;-------------------------------------
;  WRITESGF
; - - - - - -
;-------------------------------------
WRITESGF proc
    pusha
WRITERETRY:
    mov dx, OFFSET SGFSEMICOLON
    call WRITECHAR

    mov di, OFFSET SGFDATACOLOR
    shl SGFRUNNER, 1
    add di, SGFRUNNER
    shr SGFRUNNER, 1
    cmp WORD PTR [di], 0
    je WRITEEND

    cmp WORD PTR [di], OFFSET BufferBlack
    jne WRITEWHITE
    mov dx, OFFSET SGFB
    jmp WRITECOLOR
WRITEWHITE:    
    mov dx, OFFSET SGFW
WRITECOLOR:
    call WRITECHAR

    mov dx, OFFSET SGFBOXOPEN
    call WRITECHAR

    mov dx, OFFSET SGFSIGNS
    xor ax, ax
    mov di, OFFSET SGFDATAX
    add di, SGFRUNNER

    add al, BYTE PTR [di]
    add dx, ax
    call WRITECHAR

    mov dx, OFFSET SGFSIGNS
    xor ax, ax
    mov di, OFFSET SGFDATAY
    add di, SGFRUNNER

    add al, BYTE PTR [di]
    add dx, ax
    call WRITECHAR

    mov dx, OFFSET SGFBOXCLOSE
    call WRITECHAR

    inc SGFRUNNER
    cmp SGFRUNNER, SGF_MAX-1
    jae WRITEEND
    
    mov di, OFFSET SGFDATACOLOR
    shl SGFRUNNER, 1
    add di, SGFRUNNER
    shr SGFRUNNER, 1
    cmp WORD PTR [di], 0
    jne WRITERETRY
;    je WRITEEND
;    call WRITESGF

WRITEEND:    

    popa
    ret    
WRITESGF endp    

;-------------------------------------
;  WRITECHAR
; - - - - - -
; Writing a character to a file.
;-------------------------------------
WRITECHAR proc
    mov ax, 4000h
    mov bx, SGF_FID
    mov cx, 1
    int 21h
    ret
WRITECHAR endp

;-------------------------------------
;  TIMER
; - - - -
; Adding 55ms to current player-time.
;-------------------------------------
TIMER proc far
    push ax

    mov ax, @CODE
    mov es, ax

    mov ax, @DATA
    mov ds, ax

    cli

    cmp SOUND_OFF, TRUE
    je TIMER_COLOR
    inc TimeSound
    cmp TimeSound, SOUNDMAX
    jb TIMER_COLOR
    call STOPSOUND

TIMER_COLOR:    

    cmp NextPlayer, WHITE       ; See who is current player
    je TIMER_WHITE

    add TimeCounterBlack, MS55  ; Add 55ms to black
    cmp TimeCounterBlack, S1    ; Check if 1s is over
    jb TIMER_END

    sub TimeCounterBlack, S1    ; Remove 1s
    inc TimeBlack               ; Add 1s to time of black
    jmp TIMER_END

TIMER_WHITE:
    add TimeCounterWhite, MS55  ; Add 55ms to white
    cmp TimeCounterWhite, S1    ; Check if 1s is over
    jb TIMER_END

    sub TimeCounterWhite, S1    ; Remove 1s
    inc TimeWhite               ; Add 1s to time of white

TIMER_END:
    mov StartXTimes, 38
    mov StartYTimes, 19
    mov bx, TimeBlack
    call INSERTTIMES            ; Show time of black

    mov StartXTimes, 38
    mov StartYTimes, 21
    mov bx, TimeWhite
    call INSERTTIMES            ; Show time of black

    sti
    pop ax
    iret
TIMER endp

;-------------------------------------
;  SHOWMOUSE
; - - - - - -
; Shows the mousecursor.
;-------------------------------------
SHOWMOUSE proc
    push ax

    mov ax, 1
    int 33h                     ; Showing the mouse-cursor

    pop ax
    ret
SHOWMOUSE endp

;-------------------------------------
;  HIDEMOUSE
; - - - - - -
; Hides the mousecursor.
;-------------------------------------
HIDEMOUSE proc
    push ax

    mov ax, 2
    int 33h                     ; Hiding the mouse-cursor

    pop ax
    ret
HIDEMOUSE endp


;-------------------------------------
;  SETMOUSE
; - - - - - -
; Sets the mouse.
;-------------------------------------
SETMOUSE proc
    push es                     ; Saving old es
    push @DATA
    pop es                      ; Loading es with DATA

    xor ax, ax
    int 33h                     ; Reset mouse

    call SHOWMOUSE              ; Shows the mouse-cursor

    mov dx, OFFSET Cursor
    mov bx, 7h
    mov cx, 7h
    mov ax, 9
    int 33h                     ; Setting cursor-icon


    push @CODE
    pop es

    mov ax, 0014h
    mov cx, 1010100b            ; Mousebuttons 1,2,3 release
    mov dx, OFFSET MOUSEROUTINE
    int 33h                     ; Exchanging Interrupts

    mov OldMouseMask, cx        ; Saving old mask
    mov OldMouseInt, dx         ; Saving old Interrupt

    pop es                      ; Restoring old es
    ret
SETMOUSE endp

;-------------------------------------
;  UNSETMOUSE
; - - - - - - -
; Resets the mouse.
;-------------------------------------
UNSETMOUSE proc
    pusha                       ; Saving everything
    push es                     ; Saving old es

    push @CODE                  
    pop es                      ; Loading es with CODE
    
    mov ax, 0014h               
    mov cx, OldMouseMask        
    mov dx, OldMouseInt         
    int 33h                     ; Restoring old mouse-routine

    pop es                      ; Restoring old es

    call HIDEMOUSE              ; Hides the mouse-cursor
    xor ax, ax
    int 33h                     ; Resetting the mouse
    
    popa                        ; Restoring everything
    ret
UNSETMOUSE endp

;-------------------------------------
;  MOUSEROUTINE
; - - - - - - - -
; Handles mousebutton pressing and releasing.
; AX = condition mask (same bit assignments as call mask).
; BX = button state.
; CX = cursor column.
; DX = cursor row.
; SI = horizontal mickey count.
; DI = vertical mickey count
;-------------------------------------
MOUSEROUTINE proc far
    pusha                       ; Saving everything

    call HIDEMOUSE              ; Hides mousecursor

    push @DATA
    pop ds                      ; Loading ds with DATA
    push video_seg
    pop es                      ; and es with VIDEO-Segment

    mov ax, cx
    shr ax, 1                   ; Setting ax to X-Coordinate
    mov bx, dx                  ; and bx to Y-Coordinate

    cmp NextPlayer, BLACK       ; Checking who is current player
    jnz NEXT_WHITE

    mov dx, OFFSET BufferBlack  ; Loading BLACK stone into dx
    mov NextPlayer, WHITE       ; Next player : WHITE
    jmp NEXT_END
NEXT_WHITE:
    mov dx, OFFSET BufferWhite  ; Loading WHITE stone indo dx
    mov NextPlayer, BLACK       ; Next player : BLACK
NEXT_END:
                                      
    call MAKEBOARDPOSITION      ; Changing X & Y to boardpositions

    cmp bx, 176                 ; If Y > 176
    jnbe BACK                   ; then OutOfEverything (unsigned)
    cmp ax, 176                 ; If X > 176
    jnbe MENU                   ; then check menu (unsigned)

    call PLACEONBOARD           ; Placing on virtual board
    cmp PLACED, TRUE
    jne BACK                    ; Placing failed, resetting
    
    call STARTSOUND
    call PLACESTONE             ; (Placing the stone)
    jmp FORTH                   ; Move on

MENU:
    cmp bx, 176                 ; If Y < 176 
    jb BACK                     ; OutOfMenu
    cmp ax, 192                 ; If X < 192
    jb BACK                     ; OutOfMenu
    cmp ax, 208                 ; If X > 208
    ja TRYEXIT                  ; Maybe Exit pushed
    jmp BACK_END                ; Don't set colorchange back

TRYEXIT:    
    cmp ax, 288                 ; If X < 288
    jb BACK                     ; Not Exit pushed
    mov cx, esc_code            ; Load keycode
    mov ax, 500h                ; Set keystroke-store function
    int 16h                     ; Store key -> handled in main

;    jmp ENDIT                  ; Taking back changes

BACK:
    cmp NextPlayer, BLACK
    jne BACK_WHITE
    mov dx, OFFSET BufferBlack  ; Setting dx back to black
    mov NextPlayer, WHITE       ; and next to white
    jmp BACK_END
BACK_WHITE:
    mov dx, OFFSET BufferWhite  ; Setting dx back to white
    mov NextPlayer, BLACK       ; and next to black
BACK_END:
    mov PLACED, TRUE            ; PLACED back to 0
    jmp ENDIT

FORTH:

ENDIT:
    call SHOWPOINTS             ; Updating capture-points
    call SHOWMOUSE              ; Unhides mousecursor
    popa                        ; Restoring everything
    ret
MOUSEROUTINE endp

;  STARTSOUND
STARTSOUND proc
    push ax

    in al, 61h
    or al, 3
    out 61h, al

    mov al, 0B6h
    out 43h, al
    mov al, SOUND_LOW
    out 42h, al
    mov al, SOUND_HIGH
    out 42h, al

    mov SOUND_OFF, FALSE
    mov TimeSound, FREE

    pop ax
    ret
STARTSOUND endp

;  STOPSOUND
STOPSOUND proc
    push ax
    in al, 61h
    and al, 0FCh
    out 61h, al

    mov SOUND_OFF, TRUE
    pop ax
    ret
STOPSOUND endp

;-------------------------------------
;  SHOWPOINTS
; - - - - -
;-------------------------------------
SHOWPOINTS proc
    push ax

    cli
    mov StartXPoints, 38              
    mov StartYPoints, 7
    mov ax, PointsBlack
    call INSERTPOINTS           ; Showing points of black

    mov StartXPoints, 38
    mov StartYPoints, 13
    mov ax, PointsWhite
    call INSERTPOINTS           ; Showing points of white

    sti
    pop ax
    ret
SHOWPOINTS endp

;-------------------------------------
;  INSERTPOINTS
; - - - - - - - -
; ax - Points
;-------------------------------------
INSERTPOINTS proc
    pusha
IP_INSERT:
    call SETSTARTPOINTS         ; Setting startpoint
    div TEN                     ; Get last value
    add ah, 30h                 ; Transform into ASCII
    mov cx, ax
    mov dl, ah
    mov ax, 200h                ; 
    int 21h                     ; Call DOS show-character
    mov ax, cx
    xor ah,ah
    dec StartXPoints            ; Set next place
    cmp ax, 0                   ; See if there are more numbers
    jne IP_INSERT

    popa
    ret
INSERTPOINTS endp

;-------------------------------------
;  INSERTTIMES
; - - - - - - - -
; bx - Times
;-------------------------------------
INSERTTIMES proc
    pusha
IT_INSERT:
    call SETSTARTTIMES          ; Setting startpoint
    mov ax, bx
    div TEN                     ; Get last value
    mov bx, ax
    add bh, 30h                 ; Transform into ASCII
    mov cx, bx
    mov dl, bh
    mov ax, 200h                ; 
    int 21h                     ; Call DOS show-character
    mov bx, cx
    xor bh,bh
    dec StartXTimes             ; Set next place
    cmp bx, 0                   ; See if there are more numbers
    jne IT_INSERT

    popa
    ret
INSERTTIMES endp

;-------------------------------------
;  SETSTARTPOINTS
; - - - - - -
;
;-------------------------------------
SETSTARTPOINTS proc
    pusha

    mov dh, StartYPoints        ; Set X
    mov dl, StartXPoints        ; and Y values
    xor bx, bx
    mov ax, 200h
    int 10h                     ; Call Bios-Set-Cursor

    popa
    ret
SETSTARTPOINTS endp

;-------------------------------------
;  SETSTARTTIMES
; - - - - - -
;
;-------------------------------------
SETSTARTTIMES proc
    pusha

    mov dh, StartYTimes         ; Set X
    mov dl, StartXTimes         ; and Y values
    xor bx, bx
    mov ax, 200h
    int 10h                     ; Call Bios-Set-Cursor

    popa
    ret
SETSTARTTIMES endp

;-------------------------------------
;  MAKEBOARDPOSITION
; - - - - - - - - - - 
; Making xy-coordinates to exact start-position on the board.
;-------------------------------------
MAKEBOARDPOSITION proc
    sub ax, 4                   ; -4
    shr ax, 4                   ; /16 
    shl ax, 4                   ; *16
    sub bx, 4                   ; -4
    shr bx, 4                   ; /16
    shl bx, 4                   ; *16
    ret
MAKEBOARDPOSITION endp

;-------------------------------------
;  PLACEONBOARD
; - - - - - - - -
; Places the current stone on the virtual board.
; ax - X
; bx - Y
; dx - OFFSET Color
;-------------------------------------
PLACEONBOARD proc
    pusha

    push @DATA
    pop ds                      ; Loading ds with DATA
    push video_seg
    pop es                      ; Loading es with VIDEO segment

    shr ax, 4                   ; Making        (:16)
    shr bx, 4                   ; 12x12         (:16)

    call CHECKANDPLAY           ; Checking to board
    cmp PLACED, FALSE           ; If failed
    je CHECKFAILED              ; jump to end
    call ADDTOSGF               ; Adding the stone to SGF

CHECKFAILED:
    
    popa
    ret
PLACEONBOARD endp

;-------------------------------------
;  ADDTOSGF
; - - - - - - 
; Adding the currently placed stone to the SGF-Data.
; al - X-coordinate
; bl - Y-coordinate
; dx - Offset of color
;-------------------------------------
ADDTOSGF proc
    cmp SGFNUMBER, SGF_MAX-1
    jae ADD_END
    pusha
    mov di, OFFSET SGFDATACOLOR
    shl SGFNUMBER, 1
    add di, SGFNUMBER
    shr SGFNUMBER, 1

    mov [di], dx                ; Saving color for SGF

    mov di, OFFSET SGFDATAX
    add di, SGFNUMBER
    mov BYTE PTR [di], al       ; Saving X for SGF

    mov di, OFFSET SGFDATAY
    add di, SGFNUMBER
    mov BYTE PTR [di], bl       ; Saving Y for SGF

    inc SGFNUMBER
    
    popa
ADD_END:
    ret
ADDTOSGF endp

;-------------------------------------
;  CHECKANDPLAY
; - - - - - - - -
; Checks if the place where to play on is ok.
; Calls a cleanup to remove captured stones.
; ax - X
; bx - Y
; dx - Color
; . . . . . . . .
; PLACED - 1 if failed, 0 if ok
;-------------------------------------
CHECKANDPLAY proc
    pusha

    mov PLACED, TRUE            ; Assumtion: placing will be successful

    imul bx, board_size         ; Setting Y-pos
    add ax, bx                  ; Adding Y to X-pos
    shl ax, 1                   ; Setting XY-pos to WORD-XY-pos
    mov bx, OFFSET BOARD        ; Loading BOARD
    add bx, ax                  ; Going to XY-pos on BOARD
    shr ax, 1                   ; Setting XY back to BYTE-XY-pos
    cmp WORD PTR [bx], FREE     ; Checking if free
    je ITSOK                    ; 
    mov PLACED, FALSE           ; Not free
    jmp CAPEND                  ;

ITSOK:
    call VISIT
    mov WORD PTR [bx], dx       ; Setting stone on virtual board
    call LOOKAROUND             ; Check if placing is ok
    call UNVISIT

    cmp AROUND, FREE            ; 
    je CAPEND                   ; Check was ok
    mov WORD PTR [bx], FREE     ; else - remove stone
    mov PLACED, FALSE           ; Not free // not ok

    ;CHECK?
    ; Check if free
    ; Check if around is free
    ; => check if possible

CAPEND:

    popa
    ret
CHECKANDPLAY endp


;-------------------------------------
;  LOOKAROUND
; - - - - - - -
; Checking the fields around a field.
; ax - BYTE-XY-coordinate
; dx - OFFSET of buffer of stone
; . . . . . . .
; AROUND - changed according CHECKONE, 0-ok, 1-fail
;-------------------------------------
LOOKAROUND proc
    pusha

    mov AROUND, ALLFOUR         ; Assume all 4 are unfree
    mov LOOK, FREE              ; Clear Look
    xor cx, cx                  ; Clear cx

    ;////////////
    ; Field above
    inc cl                      ; Assume no-field 
    cmp ax, board_size          ; Check if XY < 12
    jb RIGHTFIELD               ; then no field above
    dec cl                      ; False assumtion

    sub ax, next_y              ; Get field above
    call CHECKONE               ; Check it
    add ax, next_y              ; Get back
    add cl, LOOK                ; See if flag was set

    ;////////////
    ; Field right
RIGHTFIELD:
    inc cl                      ; Assume no-field 
    push ax                     ; Save ax
    inc ax                      ; XY -> 1-144
    call MODSIZE                ; See if we are right
    cmp ax, 0                   ; right = 0
    pop ax                      ; Restore ax
    je DOWNFIELD                ; No field on right
    dec cl                      ; False assumtion

    inc ax                      ; Set right field
    call CHECKONE               ; Check it
    dec ax                      ; Set back
    add cl, LOOK                ; See if flag was set

    ;////////////
    ; Field below
DOWNFIELD:
    inc cl                      ; Assume no-field 
    cmp ax, 131                 ; Check if XY > 11*12-1
    ja LEFTFIELD                ; then no field below
    dec cl                      ; False assumtion

    add ax, next_y              ; Get field below
    call CHECKONE               ; Check it
    sub ax, next_y              ; Get back
    add cl, LOOK                ; See if flag was set

    ;////////////
    ; Field left
LEFTFIELD:
    inc cl                      ; Assume no-field 
    push ax                     ; Save ax
    call MODSIZE                ; See if we are left
    cmp ax, 0                   ; left = 0
    pop ax                      ; Restore ax
    je ENDFIELD                 ; No field on left
    dec cl                      ; False assumtion

    dec ax                      ; Set left field
    call CHECKONE               ; Check it
    inc ax                      ; Set back
    add cl, LOOK                ; See if flag was set

ENDFIELD:
    and AROUND, cl              ; See if all 4 directions are unfree
                                ; if yes then AROUND is UNFREE, else FREE
    popa
    ret
LOOKAROUND endp

;-------------------------------------
;  MODSIZE
; - - - -
; Divides al by board_size. 
; ax - remaining
;-------------------------------------
MODSIZE proc
    mov YVAR, 0
MODSTART:
    cmp ax, board_size          ; If ax < board_size
    jb MODEND                   ; then done
    sub ax, board_size          ; else sub board_size from ax
    inc YVAR                    ; How often does board_size fit
    jmp MODSTART                ; and check again
MODEND:
    ret
MODSIZE endp

;-------------------------------------
;  CHECKONE
; - - - - - -
; Checks a field and its surroundings.
; ax BYTE-XY-coordinate
; dx OFFSET of buffer of stone
; . . . . . .
; LOOK - changed, 0-ok, 1-not free
; STANDARD - 0 same, 1 different
;-------------------------------------
CHECKONE proc
    pusha

    mov bx, OFFSET BOARD        ; Get Board
    shl ax, 1                   ; Set ax to WORD
    add bx, ax                  ; Goto Board-position
    shr ax, 1                   ; Set ax back to BYTE
    cmp WORD PTR [bx], FREE     ; Check if free
    jne CONOTOK                 ; Not free
    mov LOOK, FREE              ; Free -> ok
    jmp COEND                   ; End it

CONOTOK:
    mov cx, [bx]
    mov MYCOLOR, cx             ; Save current stone-color
    call CHECKAROUND            ; Check fields around
    call UNVISIT
    cmp cx, dx                  ; Check color: same or diff
    jne CODIFF
    mov bl, COVAR
    mov LOOK, bl                ; Same stones: look = covar
    jmp COEND
CODIFF:
    mov LOOK, UNFREE            ; Diff stones: look = !covar
    cmp COVAR, FREE             ; Other had free place
    je COEND                    ; so end
    mov LOOK, FREE              ; else it will be free

    ;///////////////////
    ; Clearing captured
    mov COUNT, 0                ; Set COUNT to 0
    call ERASE                  ; Remove captured stones
    call UNVISIT

    ;/////////////////
    ; Adding Captured
    cmp dx, OFFSET BufferBlack  ; Check for player
    jne ADDWHITE                ; no -> to white
    mov cx, PointsBlack         ; Load black points
    add cx, COUNT               ; Add new value
    mov PointsBlack, cx         ; Add points to black
    jmp COEND

ADDWHITE:
    mov cx, PointsWhite         ; Load white points
    add cx, COUNT               ; Add new value
    mov PointsWhite, cx         ; Add points to white

COEND:
    popa
    ret
CHECKONE endp

;-------------------------------------
;  VISIT
; - - - -
; Sets a place an CHECKBOARD to UNFREE.
;-------------------------------------
VISIT proc
    push bx                     ; Save bx
    mov bx, OFFSET CHECKBOARD   ; Load CHECKBOARD
    add bx, ax                  ; Set position
    mov BYTE PTR [bx], UNFREE   ; Set Unfree
    pop bx                      ; Restore bx
    ret
VISIT endp

;-------------------------------------
;  UNVISIT
; - - - -
; Sets a place an CHECKBOARD to FREE.
;-------------------------------------
UNVISIT proc
    push bx                     ; Save bx
    push cx                     ; Save cx
    mov cx, 72                  ; Load counter with 144/2
    mov bx, OFFSET CHECKBOARD   ; Load CHECKBOARD
UN72:    
    mov WORD PTR [bx], FREE     ; Set Free
    add bx, 2                   ; Next WORD
    loop UN72                   ; White (--cx) 
    pop cx                      ; Restore cx
    pop bx                      ; Restore bx
    ret
UNVISIT endp

;-------------------------------------
;  CHECKAROUND
; - - - - - - -
; Recursive check of field and surroundings.
; ax - BYTE-XY-coordinate
; dx - OFFSET of color of stone to place
; STANDARD - Set to 0 if same or 1 else
;-------------------------------------
CHECKAROUND proc
    pusha
    mov COVAR, UNFREE           ; Assume unfree

    ;///////////////
    ; Is this free?
    mov bx, OFFSET BOARD        ; Load BOARD to bx
    shl ax, 1                   ; Set XY to WORD
    add bx, ax                  ; Goto XY on BOARD
    shr ax, 1                   ; Set XY back to BYTE
    cmp WORD PTR [bx], FREE     ; See if field is free
    je CA_FREEEND               ; It's free to play

    mov cx, [bx]
    cmp cx, MYCOLOR             ; If color != mycolor
    jne CA_END                  ; -> end

    ;/////////////////////////
    ; Check the virtual board
    mov bx, OFFSET CHECKBOARD   ; Load checkboard
    add bx, ax                  ; with position
    cmp BYTE PTR [bx], UNFREE   ; and see if we were here
    je CA_END                   ; if so then end

    mov BYTE PTR [bx], UNFREE   ; else set visited

    ;/////////////////////////////
    ; Now check around that field

    ;///////
    ; above
    cmp ax, board_size          ; See if there is a field above
    jb CA_RIGHT
    
    sub ax, next_y              ; Set to above
    call CHECKAROUND            ; Check that
    add ax, next_y              ; Set back

    cmp COVAR, FREE             ; See what happend
    je CA_UNSETEND              ; End if free

    ;///////
    ; right
CA_RIGHT:
    push ax                     ; Save ax
    inc ax                      ; Make 1-144
    call MODSIZE
    cmp ax, 0                   ; See if ax was multiple of 12
    pop ax                      ; Restore ax
    je CA_BELOW                 ; One of right fields - so no right there

    inc ax                      ; Set right field
    call CHECKAROUND            ; Check it
    dec ax                      ; Set back
    
    cmp COVAR, FREE             ; See what happend
    je CA_UNSETEND              ; End if free

    ;///////
    ; below
CA_BELOW:
    cmp ax, 131                 ; See if there is a field below
    ja CA_LEFT                  ; Last line -> next test

    add ax, next_y              ; Set to below
    call CHECKAROUND            ; Check it
    sub ax, next_y              ; Set back

    cmp COVAR, FREE             ; See what happend
    je CA_UNSETEND              ; End if free

    ;//////
    ; left
CA_LEFT:
    push ax                     ; Save ax
    call MODSIZE                
    cmp ax, 0                   ; See if mod is 0
    pop ax                      ; Restore ax
    je CA_UNSETEND              ; if 0 -> no left field -> end

    dec ax                      ; Set left
    call CHECKAROUND            ; Check it
    inc ax                      ; Set back

    jmp CA_UNSETEND

CA_FREEEND:
    mov COVAR, FREE             ; Free to play

CA_UNSETEND:
;    call UNVISIT                ; Remove Visit status
                                ; Will be done after all checks

CA_END:
    popa
    ret
CHECKAROUND endp

;-------------------------------------
; ERASE
; - - - -
; ax
; dx
; . . . .
; COUNT - Number of removed stones
;-------------------------------------
ERASE proc
    pusha

    mov COVAR, UNFREE           ; Assume unfree

    ;///////////////
    ; Is this free?
    mov bx, OFFSET BOARD        ; Load BOARD to bx
    shl ax, 1                   ; Set XY to WORD
    add bx, ax                  ; Goto XY on BOARD
    shr ax, 1                   ; Set XY back to BYTE
    cmp WORD PTR [bx], FREE     ; See if field is free
    je ERASE_FREEEND            ; It's free to play

    mov cx, [bx]
    cmp cx, MYCOLOR             ; If color != mycolor
    jne ERASE_END               ; -> end

    ;/////////////////////////
    ; Check the virtual board
    mov bx, OFFSET CHECKBOARD   ; Load checkboard
    add bx, ax                  ; with position
    cmp BYTE PTR [bx], UNFREE   ; and see if we were here
    je ERASE_END                ; if so then end

    mov BYTE PTR [bx], UNFREE   ; else set visited

    ;/////////////////////////////
    ; Now check around that field
    xor cx, cx                  ; Clear cx

    ;///////
    ; above
    cmp ax, board_size          ; See if there is a field above
    jb ERASE_RIGHT
    
    sub ax, next_y              ; Set to above
    call ERASE                  ; Check that
    add ax, next_y              ; Set back

    add cl, COVAR               ; Add 1/0 to COVAR
;    cmp COVAR, FREE             ; See what happend
;    je ERASE_UNSETEND           ; End if free

    ;///////
    ; right
ERASE_RIGHT:
    push ax                     ; Save ax
    inc ax                      ; Make 1-144
    call MODSIZE
    cmp ax, 0                   ; See if ax was multiple of 12
    pop ax                      ; Restore ax
    je ERASE_BELOW              ; One of right fields - so no right there

    inc ax                      ; Set right field
    call ERASE                  ; Check it
    dec ax                      ; Set back
    
    add cl, COVAR               ; Add 1/0 to COVAR
;    cmp COVAR, FREE             ; See what happend
;    je ERASE_UNSETEND           ; End if free

    ;///////
    ; below
ERASE_BELOW:
    cmp ax, 131                 ; See if there is a field below
    ja ERASE_LEFT               ; Last line -> next test

    add ax, next_y              ; Set to below
    call ERASE                  ; Check it
    sub ax, next_y              ; Set back

    add cl, COVAR               ; Add 1/0 to COVAR
;    cmp COVAR, FREE             ; See what happend
;    je ERASE_UNSETEND           ; End if free

    ;//////
    ; left
ERASE_LEFT:
    push ax                     ; Save ax
    call MODSIZE                
    cmp ax, 0                   ; See if mod is 0
    pop ax                      ; Restore ax
    je ERASE_UNSETEND           ; if 0 -> no left field -> end

    dec ax                      ; Set left
    call ERASE                  ; Check it
    inc ax                      ; Set back

    add cl, COVAR               ; Add 1/0 to COVAR

    jmp ERASE_UNSETEND

ERASE_FREEEND:
    mov COVAR, FREE             ; Free to play
    jmp ERASE_END

ERASE_UNSETEND:
    shl cl, 2                   ; cl/4; if cl = 4 -> 1, else cl = 0
    mov COVAR, cl               ; 1-> unfree, 0-> free
;    call UNVISIT                ; Remove Visit status
                                ; Done after all erased
    call ERASEME                ; Remove stone
    inc COUNT                   ; Adding one stone to erased

ERASE_END:
    popa
    ret
ERASE endp

;-------------------------------------
;  ERASEME
; - - - - -
; ax - Byte-XY-coordinate
;-------------------------------------
ERASEME proc
    pusha

    ;///////////////////////////
    ; Removing stone from BOARD
    shl ax, 1                   ; Make WORD XY pos
    mov bx, OFFSET BOARD        ; Load BOARD
    add bx, ax                  ; Set pos
    mov WORD PTR [bx], FREE     ; Clear
    shr ax, 1                   ; Reset to BYTE XY pos

    ;/////////////////////////
    ; Removing stone from GUI
    mov dx, OFFSET BufferField  ; Setting field color
    call MODSIZE                ; Getting X and Y
    mov bx, YVAR                ; Saving Y at bx
    shl ax, 4                   ; ax * field_size (16)
    shl bx, 4                   ; bx * field_size (16)
    call PLACESTONE             ; Removing the stone

    popa
    ret
ERASEME endp    

;-------------------------------------
;  KIMOVE
; - - - - -
;-------------------------------------
KIMOVE proc
    pusha

    add ax, KISAVE
    add ax, TimeCounterBlack
    add ax, TimeCounterWhite
    add ax, TimeBlack
    add ax, TimeWhite
KIDIV:
    cmp ax, 144
    jb KINEXT
    sub ax, 144
    inc KISAVE
    jmp KIDIV

KINEXT:              
    xor dx, dx
    
KIX:
    cmp ax, board_size
    jb KIY
    sub ax, board_size
    inc dx
    jmp KIX
KIY:
    shl ax, 5
    add ax, 32
    mov cx, ax

    shl dx, 4
    add dx, 16

    call MOUSEROUTINE
    popa

    ret
KIMOVE endp

;-------------------------------------
;  PLACESTONE
; - - - - - -
; Placing a stone on the board.
; ax x-coordinate
; bx y-coordinate
; dx OFFSET of buffer of stone
;-------------------------------------
PLACESTONE proc
    call HIDEMOUSE              ; Hiding mouse-cursor

    pusha                       ; Saving everything
    
    push @DATA
    pop ds                      ; Loading @DATA to ds
    push video_seg
    pop es                      ; Loading the VideoSegmenet to es

    add bx, 4                   ; Moving start 4px down to center the board
    imul bx, win_width          ; Setting the startposition on screen
    mov di, ax                  ; ( y * window_width + x)
    add di, bx                   
    add di, 4                   ; Moving start 4px right

    mov si, dx                  ; Setting stone to place
    mov bx, field_size          ; Setting height to field_size

    cli
ROW:
    mov cx, field_size          ; Setting width to field_size
COL:
    movsb                       ; Moving ds:si to es:di
    loop COL                    ; for complete field_size
    add di, win_width - field_size ; Switching to next line
    add si, 256                 ; Adding 16*16 = 256 to si for next line
    dec bx                      ; one less row to go
    jnz ROW

    sti

    popa                        ; Restoring everything

    call SHOWMOUSE              ; Showing mouse-cursor
    ret
PLACESTONE endp    

;------------------------------------------------------------------------------
;  DRAWBOARD
; - - - - - -
; Draws the board on the screen. The size will be board_size*board_size.
;------------------------------------------------------------------------------
DRAWBOARD proc
      xor bx, bx
      mov dx, OFFSET BufferField  ; Setting color of board 
      mov ch, board_size          ; Making board height
ROW1: mov cl, board_size          ; x width fields big
      xor ax, ax
COL1: call PLACESTONE             ; Place a field-stone
      add ax, field_size          ; Move to next X stone
      dec cl
      cmp cl, 0
      jne COL1
      add bx, field_size          ; Move to next Y stone
      dec ch
      cmp ch, 0
      jne ROW1
      ret
DRAWBOARD endp

;== END ==
end GoASM
