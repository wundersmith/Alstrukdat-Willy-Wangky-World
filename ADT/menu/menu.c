#include <stdio.h>
#include "menu.h"


Graph GraphPeta;
MATRIKS Peta1, Peta2, Peta3, Peta4;
TreeWahanaS UpgradeTree;
player Player;
// ListWahanaD WahanaBuilt;

void MainMenu(){
    printf("          _ _ _                                   _          _\n");     
    printf("         (_| | |                                 | |        ( )\n");    
    printf("__      ___| | |_   _  __      ____ _ _ __   __ _| | ___   _|/ ___\n"); 
    printf("\\ \\ /\\ / | | | | | | | \\ \\ /\\ / / _` | '_ \\ / _` | |/ | | | | / __|\n");
    printf(" \\ V  V /| | | | |_| |  \\ V  V | (_| | | | | (_| |   <| |_| | \\__ \\\n");
    printf("  \\_/\\_/ |_|_|_|\\__, |   \\_/\\_/ \\__,_|_| |_|\\__, |_| \\_\\__, | |___/\n");
    printf("                 __/ |                       __/ |      __/ |\n");      
    printf("                |___/                       |___/      |___/       \n");
    printf("          __     __  ______  ______  __      _____\n");    
    printf("         /\\ \\  _ \\ \\/\\  __ \\/\\  == \\/\\ \\    /\\  __-.\n");  
    printf("         \\ \\ \\/ \".\\ \\ \\ \\/\\ \\ \\  __<\\ \\ \\___\\ \\ \\/\\ \\\n"); 
    printf("          \\ \\__/\".~\\_\\ \\_____\\ \\_\\ \\_\\ \\_____\\ \\____-\n"); 
    printf("           \\/_/   \\/_/\\/_____/\\/_/ /_/\\/_____/\\/____/\n\n"); 
                                             
    printf("====================================================================\n\n");
    printf("                Welcome to Willy Wangky's World!\n");
    printf("Here, you can make your own amusement park and do so many fun stuff!\n\n");
    printf("====================================================================\n\n");
    printf(" __| |_______________| |__                __| |________________| |__\n");
    printf("(__   _______________   __)              (__   ________________   __)\n");
    printf("   | |               | |                    | |                | |\n");
    printf("   | |     N E W     | |                    | |     E X I T    | |\n");
    printf(" __| |_______________| |__                __| |________________| |__\n");
    printf("(__   _______________   __               (__   ________________   __ \n");
    printf("   | |               | |                    | |                | |\n\n");
    printf("====================================================================\n");
    STARTKATA();

    printf("====================================================================\n");
}

void MenuJalan(player *p1, Graph G){
    CJam(*p1) = NextMenit(CJam(*p1));
    if (IsKataSama("w")){
        w(p1, G);
    }else if (IsKataSama("a")){
        a(p1, G);
    }else if (IsKataSama("s")){
        s(p1, G);
    }else if (IsKataSama("d")){
        d(p1, G);
    }
}

void ListCommand(){
    printf("================================================================\n");
    printf("New Game: \"new\"\n");
    printf("Load Game: \"load\"\n");
    printf("Berjalan ke atas: \"w\"\n");
    printf("Berjalan ke kiri: \"a\"\n");
    printf("Berjalan ke bawah: \"s\"\n");
    printf("Berjalan ke kanan: \"d\"\n");
    printf("Bangun wahana: \"build\"\n");
    printf("Upgrade wahana: \"upgrade\"\n");
    printf("Beli item: \"buy\"\n");
    printf("Undo: \"undo\"\n");
    printf("Pergi ke Main Phase tanpa execute (stack): \"main\"\n");
    printf("Pergi ke Main Phase dengan execute (stack): \"execute\"\n");
    printf("Melayani pelanggan saat main phase: \"main\"\n");
    printf("Melayani pengunjung: \"serve <nama wahana>\"\n");
    printf("   Hanya bisa digunakan ketika pemain berada di sebelah antrian\n");
    printf("Memperbaiki wahana: \"repair\"\n");
    printf("   Hanya bisa digunakan ketika pemain berada di sebelah wahana\n");
    printf("Melihat detail wahana: \"detail\"\n");
    printf("   Hanya bisa digunakan ketika pemain berada di sebelah wahana\n");
    printf("Masuk office: \"office\"\n");
    printf("   Hanya bisa digunakan ketika pemain berada di atas office\n");
    printf("Pergi ke Preparation Phase: \"prepare\"\n");
    printf("Keluar Game: \"exit\"\n");
    printf("================================================================\n");
}

void Preparation(player *p1){
    do{
        if (!IsKataSama("command")){
            printf("====================================\n");
            printf("        Preparation Phase\n");
            printf("             Day %d\n", Day(*p1));
            printf("===================================\n");
            TulisPETA(*p1, GraphPeta);
            printf("===================================\n");
            printf("Legend:\n");
            printf("A = Antrian\n");
            printf("P = Player\n");
            printf("W = Wahana\n");
            printf("O = Office\n");
            printf("^, >, v, < = Gerbang\n");
            printf("===================================\n");
            TulisPlayer();
            printf("Current Time: "); TulisJAM(CJam(*p1)); printf("\n");
            printf("Opening Time: "); TulisJAM(JamBuka); printf("\n");
            printf("Time Remaining:"); TulisTimeRemaining(Durasi(CJam(*p1), JamBuka)); 
            printf("\n");
            // Total aksi yang akan dilakukan:
            // Total waktu yang dibutuhkan:
            // Total uang yang dibutuhkan:
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
            printf("\n");
        }
        
        printf("Masukkan perintah: ");
        STARTKATA();

        if (IsKataSama("w") || IsKataSama("a") || IsKataSama("s") || IsKataSama("d")){
           MenuJalan(p1, GraphPeta);
        } else if (IsKataSama("command")){
            ListCommand();
        } else if (IsKataSama("build")){
            buildWahana(Position(Player), &WahanaBuilt);
            AddWToPeta();
        } else if (IsKataSama("buy")){
            CommmandBuyArray();
        }
        // nanti tambahin elif aja buat command yang lain
        else if(!(IsKataSama("main") || IsKataSama("exit") || IsKataSama("execute"))){
            printf("==========================================================\n");
            printf("Command tidak tersedia\n");
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
            printf("Masukkan perintah: ");
            STARTKATA();
        }
    } while (!(IsKataSama("main") || IsKataSama("exit") || IsKataSama("execute")));
}

void MainPhase(player * p1){
    PrioQueue Q;
    listPlayer LP;
    infoLP del;
    boolean enter = false;
    CreateEmptyQueue(&Q, 5);
    CreateEmptyLP(&LP);
    if (!IsEmptyListW(WahanaBuilt)) {
        RandomizeQueue(&Q, WahanaBuilt);
    }

    do{
        if(enter && !IsEmptyQueue(Q)){
            ReducePatience(&Q);
            Q = AngryCustomer(Q);
        }
        
        if(!IsEmptyLP(LP)){
            ReduceTime(&LP);
            for(int i = 0; i < CountCompleted(LP); i++) {
                DelCompleted(&LP, &del);
                FirstEnqueue(&Q, del);
            }
        }

        enter = true;

        
        if (!IsKataSama("command")){
            printf("===================================\n");
            printf("            Main Phase\n");
            printf("             Day %d\n", Day(*p1));
            printf("===================================\n");
            TulisPETA(*p1, GraphPeta);
            printf("===================================\n");
            printf("Legend:\n");
            printf("A = Antrian\n");
            printf("P = Player\n");
            printf("W = Wahana\n");
            printf("O = Office\n");
            printf("^, >, v, < = Gerbang\n");
            printf("===================================\n");
            printf("\n");
            TulisPlayer(); //print nama dan uang
            printf("Current Time: "); TulisJAM(CJam(*p1)); printf("\n");
            printf("Closing Time: "); TulisJAM(JamTutup); printf("\n");
            printf("Time Remaining:"); TulisTimeRemaining(Durasi(CJam(*p1), JamTutup)); 
            printf("\n");
            printf("\n");
            if (IsEmptyListW(WahanaBuilt)) {
                printf("Tidak ada wahana yang tersedia.\n");
            } else{
                if(!IsEmptyQueue(Q)){
                    printf("Antrian [%d/5] :\n", NbElmtQueue(Q));
                    PrintPrioQueue(Q);
                } else {
                    printf("Antrian kosong\n");
                }
            }
            printf("\n");
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
            printf("\n");
        }
        printf("Masukkan perintah: ");
        
        STARTKATA();
        if (IsKataSama("w") || IsKataSama("a") || IsKataSama("s") || IsKataSama("d")){
           MenuJalan(p1, GraphPeta);
        } else if (IsKataSama("command")){
            ListCommand();
        } else if (IsKataSama("serve")) {
            ADVKATA();
            Serve(p1, CKata, &Q, &LP, WahanaBuilt);
            // addressGraph CPeta = FirstGraph(GraphPeta);
            // int x = X(*p1), y = Y(*p1);
            // while(ID(CPeta) != MapNum(*p1)){
            //     CPeta = NextGraph(CPeta);
            // }
            // ADVKATA();
            // if(Elmt(Peta(CPeta), x + 1, y) == 'A' || Elmt(Peta(CPeta), x, y+1) == 'A' || Elmt(Peta(CPeta), x - 1, y) == 'A' || Elmt(Peta(CPeta), x, y - 1) == 'A'){
            // } else {
            //     printf("Silahkan pergi ke sebelah antrian untuk menggunakan command ini \n\n");
            // }
        }
        // nanti tambahin elif aja buat command yang lain 
        // else if (!(IsKataSama("prepare") || IsKataSama("exit"))) {
        //     printf("==========================================================\n");
        //     printf("Command tidak tersedia\n");
        //     printf("==========================================================\n");
        //     printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
        //     printf("==========================================================\n");
        // } 
        else if (!(IsKataSama("prepare") || IsKataSama("exit"))) {
            printf("==========================================================\n");
            printf("Command tidak tersedia\n");
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
            printf("Masukkan perintah: ");
            STARTKATA();
        } 
        
    } while(!(IsKataSama("prepare") || IsKataSama("exit")));
}