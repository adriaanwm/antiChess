#!/usr/bin/python

import gtk
import time

'''Requested Window Size In Pixels'''
windowSizeX = 600 
windowSizeY = 600
ScoreSectionY = 30

'''Number of Chess Squares'''
BSqrX = 8
BSqrY = 8
BSqrTotal = (BSqrY * BSqrX)


'''Window Title'''
WinTitle = "AntiChess"





'''The main display window for AntiChess'''
class ACWindow(gtk.Window):

    def __init__(Self):
        super(ACWindow, Self).__init__()
        
        Self.connect("destroy", gtk.main_quit)
        Self.set_size_request(windowSizeX, (windowSizeY + ScoreSectionY))
        Self.set_position(gtk.WIN_POS_CENTER)
        Self.set_title(WinTitle)

        ScoreContainer = gtk.Frame(label=None)

    
        CBTable = gtk.Table(BSqrX, BSqrY, True)

        button = gtk.Button("My FUCKING BUTTON")
        button.connect("clicked", Self.DrawSquaes)

        Self.add(ScoreContainer)
        Self.add(CBTable)
        CBTable.add(button)


        Self.show_all()


    def DrawSquaes(Passed, Self):
        print "FUCK HER RIGHT IN THE PUSSY"
        Passed.set_title("LOL IM A\n NIGGER") 

ACWindow()
gtk.main()

