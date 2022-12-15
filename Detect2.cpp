#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
//#include <unistd.h>
#include <string>
#include <chrono>
#include <thread>
#include <time.h>
#include <algorithm>
#include <vector>
#define br break;
using namespace std;
typedef string ss;

int choise;
bool first_l = false;
unsigned int gl_sl = 500;
int lim = 2;
bool clean_flag = false;
map <string, int> endings;
map <string, bool> used_loc;
ss uni_ans = "\033[32mПожалуй давайте вернемся\033[0m";
map <ss, ss> places;
vector <ss> choises = { "1 - Выйти на улицу", "2 - Зайти на кухню", "3 - Осмотреть зал", "4 - Осмотреть ванную" ,"5 - Сдаться" };
vector <ss> pl2 = { "outdoor", "kitchen", "living_room", "bathroom" };
// Инициализация функций, которые будут использоваться //
void begin_game();

//Выборы//
void cleaning_choise();
void begin_choise();
void default_choise();
void outdoor_choise();
void kitchen_choise();
void living_room_choise();
void bathroom_choise();
void smelling_choise();
void break_tarelka();
void otpechat_choise();
void end_game_concid();
void living_room_kastrula_choise();
void doga();
void dima();
void roma();
//Системные штуки
void end_game();
void text_out(ss text);
void clear_console();
void waiting();
void sleep_l(unsigned int milliseconds_);
void change_color(ss color, ss j);
void reset_color();
/////////////////////////////////////////////////////////

void begin_game() {
    ss hello_text = "-Ало, это детективное агенство Шомана Ремцова, это Матвей Разинов. Я хочу воспользоваться вашими услугами частного детектива.";
    ss agree_text = "-Здравствуйте, да, выезжаю прямо сейчас диктуйте адрес…";
    ss wrong_text = "-Нет, спасибо я не работаю с Матвеями.";
    ss adress_text = "-Да, записывайте, Улица Пушкина Дом Калатушкина.";
    text_out(hello_text);
    cout << "1 - Согласится\n2 - Отказаться\n";
    cin >> choise;
    switch (choise)
    {
    case 1:
        text_out(agree_text);
        text_out(adress_text);
        sleep_l(gl_sl);
        endings["other_end"]++;
        cleaning_choise();
        br;
    case 2:
        text_out(wrong_text);
        exit(0);
        br;
    }
}

void cleaning_choise() {
    clear_console();
    ss moi_text = "...оо палмолив мой нежный гель";
    ss wrong_text = "*Фу, ну я и грязный конечно, ну да не страшно. Панку нужны только три вещи...\nИ не стирать их*";
    text_out("Помыться?");
    cout << "1 - Да\n2 - Нет\n";
    cin >> choise;
    switch (choise) {
    case 1:
        change_color("34", "1");
        text_out(moi_text);
        sleep_l(gl_sl);
        clean_flag = true;
        endings["dog_end"]++;
        reset_color();
        br;
    case 2:
        change_color("31", "4");
        text_out(wrong_text);
        sleep_l(gl_sl);
        reset_color();
        br;
    }
    waiting();
    ss hello_text = "-Здравствуйте, детектив Шоман Ремцов.Спасибо, что согласились помочь в расследовании этого дела. \nК сожалению многие отказались от него, возможно из-за его абсурдности, но оно очень важно для меня. \nСегодня 12 ноября 2022 года, мы находимся в моей квартире, здесь небольшой беспорядок, так как 141 группа факультета КниИТ праздновала написание коллоквиума, если вам интересно то у меня 9 баллов.\nИ произошла одна неприятная вещь… Во время празднования кто-то украл сосиски из холодильника сварил их и съел. \nДом в вашем распоряжении можете все обыскать. Возможно вы обнаружите улики..";
    text_out(hello_text);
    begin_choise();
}
/////////////////////////////////////////////////
void begin_choise() {
    bool flag = true;
    for (auto loc : used_loc)
        flag *= loc.second;
    if (flag) {
        ss end_text = "Кажется мы сходили во все комнаты, и изучили каждую улику\n Теперь я могу сказать вам, кто же является вором сосисок\n";
        change_color("33", "4");
        text_out(end_text);
        reset_color();
        change_color("32", "1");
        cout << "1 - Назвать имя вора\n";
        reset_color();
        change_color("31", "1");
        cout << "2 - Убежать\n";
        reset_color();
        cin >> choise;
        switch (choise) {
        case 1:
            end_game();
            br;
        case 2:
            end_game_concid();
            br;
        }
    }
    else {
        if (first_l) {
            clear_console();
            change_color("32", "");
            text_out("Кажется мы зашли еще не во все комнаты, давайте продолжим\n");
            reset_color();
        }
        places["outdoor"] = choises[0];
        places["kitchen"] = choises[1];
        places["living_room"] = choises[2];
        places["bathroom"] = choises[3];
        for (auto place : pl2) {
            if (used_loc[place] == true) {
                change_color("32", "1");
            }
            else {
                change_color("33", " ");
            }
            cout << places[place] << endl;
            reset_color();
        }
        change_color("31", "4");
        cout << choises[4] << endl;
        reset_color();
        //cout << "1 - Выйти на улицу\n2 - Зайти на кухню\n3 - Осмотреть зал\n4 - Осмотреть ванную\n5 - Сдаться\n";
        cin >> choise;
        switch (choise) {
        case 1:
            outdoor_choise();
            br;
        case 2:
            kitchen_choise();
            br;
        case 3:
            living_room_choise();
            br;
        case 4:
            bathroom_choise();
            br;
        case 5:
            end_game_concid();
            br;
        }
    }
}

void bathroom_choise() {
    first_l = true;
    ss rtext = "*заходят в ванную*\nТут только грязный кошачий лоток, стаканчик с бритвами и зубной щеткой.\nНедовольная кошка пьющая воду.Пожалуй больше не будем сюда заходить.Здесь нет ничего интересного.";
    if (used_loc["bathroom"])
        default_choise();
    else {
        used_loc["bathroom"] = true;
        change_color("36", "1");
        text_out(rtext);
        reset_color();
    }
    sleep_l(300);
    clear_console();
    begin_choise();
}

void outdoor_choise() {
    first_l = true;
    if (used_loc["outdoor"])
        default_choise();
    else {
        used_loc["outdoor"] = true;
        ss begin_text = "-Для начала давайте осмотрим улицу.";
        ss description_text = "*выходят на улицу* \nПеред вами открывается пустынный ноябрьский, холодный пейзаж Волжского района.\nНа улице лежит мусорный пакет с бутылками, бычками сигарет.\nВы с энтузиазмом роетесь в пакете и обнаруживаете там пленки от сосисок.";
        ss ans1 = "-Да, это она, и что нам это дает, ведь я собирал мусор ночью и мало что помню…";
        ss ans1_dec = "-Возможно вам кто-то помогал, и этот кто-то не хотел, чтобы вы вспомнили о сосисках.";
        ss ans2 = "-Какой-то вы молчун…";
        change_color("34", " ");
        text_out(description_text);
        reset_color();
        cout << "1 - Спросить является ли эти пленки пленками от тех сосисок\n2 - Многозначительно промолчать\n3 - Вернуться назад\n";
        cin >> choise;
        switch (choise) {
        case 1:
            text_out(ans1);
            text_out(ans1_dec);
            endings["true_end"]--;
            sleep_l(gl_sl);
            br;
        case 2:
            text_out(ans2);
            endings["true_end"]++;
            sleep_l(gl_sl);
            br;
        case 3:
            clear_console();
            text_out(uni_ans);
            sleep_l(500);
            used_loc["outdoor"] = false;
        }
        clear_console();
        begin_choise();
    }
}

void kitchen_choise() {
    first_l = true;
    if (used_loc["kitchen"])
        default_choise();
    else {
        used_loc["kitchen"] = true;
        ss hello_text = "-Для начала давайте осмотрим кухню.";
        ss description_text = "*заходят на кухню*\nКоробки от пиццы, грязная посуда, куча пепельниц сделанных из всего, что было под рукой.\nУжасная вонь.Видите единственную тарелку на столе, на ней тонкая пленка бульона.";
        ss ans1 = "– Что-то мне не нравится ваше поведение, зачем вы нюхаете тарелку?";
        ss ans2 = "ЧТО ВЫ ТВОРИТЕ????? ВЫ В СВОЕМ УМЕ, А ЕСЛИ Я ПОРЕЖУСЬ??? \nИ вообще эта тарелка стоит денег…";
        change_color("33", "1");
        text_out(description_text);
        reset_color();
        cout << "1 - Понюхать тарелку\n2 - Взять тарелку и бросить об стену\n3 - Помыть тарелку\n4 - Вернуться\n";
        cin >> choise;
        switch (choise) {
        case 1:
            text_out(ans1);
            smelling_choise();
            endings["other_end"]++;
            br;
        case 2:
            text_out(ans2);
            break_tarelka();
            endings["true_end"]++;
            br;
        case 3:
            clear_console();
            begin_choise();
            endings["other_end"]++;
            br;
        case 4:
            clear_console();
            text_out(uni_ans);
            sleep_l(500);
            used_loc["kitchen"] = false;
        }
    }
}

void living_room_choise() {
    first_l = true;
    if (used_loc["living_room"])
        default_choise();
    else {
        used_loc["living_room"] = true;
        ss description_text = "*заходят в зал*\nПо дивану прыгает маленькая собачка Фифа.Она радостно бежит к вам и обнюхивает вас.";
        ss hello_text = "-Для начала давайте осмотрим зал.";
        ss var_txt = "Хмм моя собака очень рада вас видеть и виляет хвостом, как будто она вас когда-то видела";
        ss next_text = "На грязном столе, покрытым странными сладкими пятнами красуется алюминиевая кастрюлька.";
        text_out(hello_text);
        change_color("32", "1");
        text_out(description_text);
        reset_color();
        if (!clean_flag) {
            endings["true_end"]++;
            text_out(var_txt);
        }
        text_out(next_text);
    }
    ss dog_end_text = "Отлично, дело раскрыто, в преть советую вам получше следить за собакой \nДенег не возьму, но можете одолжить велосипед на выходные, я хочу поработать кхм кхм…";
    ss ans1 = "-Почему вы так в этом уверены? \nВаша собака очень обрадовалась вам, и я честно очень сомневаюсь в том, что она могла сама сварить сосиски.";
    ss kastr_descr = "*Алюминиевая, ручка вяло болтается на слабом шурупчике. \nУниверсальная кастрюля, в ней можно и пельмешек сварить и черпать воду, если вдруг затопит...*";
    ss quest1 = "-Да, я рад, что вам понравилось, но все таки как это поможет делу?";
    cout << "1 - Обвинить собаку\n2 - Осмотреть кастрюлю\n3 - Уйти\n";
    cin >> choise;
    switch (choise) {
    case 1:
        if (endings["dog_end"] >= 1 && endings["true_end"] < lim) {
            doga();
            exit(0);
        }
        else {
            text_out(ans1);
            sleep_l(gl_sl);
            endings["true_end"]++;
        }
        br;
    case 2:
        text_out(kastr_descr);
        text_out(quest1);
        living_room_kastrula_choise();
        sleep_l(300);
        br;
    case 3:
        clear_console();
        text_out(uni_ans);
        sleep_l(500);
        used_loc["living_room"] = false;
    }
    begin_choise();
}

void smelling_choise() {
    cout << "1 -Это важная часть следствия, вы вообще книитовец, что вы знаете о детективах?\n2 - Я просто люблю нюхать тарелки... Вот такой я человек.\n";
    ss ans1 = "-Ой пук мук… ну я играл в диско элизиум…";
    ss ans2 = "-Я просто люблю нюхать тарелки... Вот такой я человек.";
    ss ans3 = "А… ну да";
    cin >> choise;
    switch (choise) {
    case 1:
        text_out(ans1);
        br;
    case 2:
        text_out(ans2);
        endings["true_end"]++;
        br;
    }
    text_out(ans3);
    sleep_l(gl_sl);
    //kitchen_choise();
    begin_choise();
}

void break_tarelka() {
    ss ans2 = "-Спасибо, вы очень честный детектив-маг, поставлю хороший отзыв на сайте детективы-маги.ком";
    ss ans3 = "-Возможно и так… Иногда она меня тоже пугает.";
    ss ans1 = "АААА да, понятно)";
    cout << "1 - Ничего страшного я просто проверял её на прочность\n2 - Извините, за такой резкий прием, но помимо детектива я являюсь потомственным магом и в вашем доме я заметил злого духа и пришиб его тарелкой, но денег за это не возьму…\n3 - -Ваша собака на меня косо посмотрела, возможно она что-то знает\n";
    cin >> choise;
    switch (choise) {
    case 1:
        text_out(ans1);
        endings["true_end"]++;
        br;
    case 2:
        text_out(ans2);
        endings["other_end"]++;
        br;
    case 3:
        text_out(ans3);
        endings["dog_end"]++;
    }
    sleep_l(gl_sl);
    //kitchen_choise();
    begin_choise();
}

void living_room_kastrula_choise() {
    ss nrav = "Да, отлично, какой-то вы странный детектив.. Кажется я вас где-то видел";
    cout << "1 - -Сейчас я сниму отпечатки пальцев и мы узнаем всю правду!!\n2 - Да мне просто очень понравилась кастрюля))\n";
    cin >> choise;
    switch (choise) {
    case 1:
        otpechat_choise();
        endings["other_end"]++;
        br;
    case 2:
        text_out(nrav);
        endings["true_end"]++;
        begin_choise();
        br;
    }
}

void otpechat_choise() {
    ss nu_text = "Тут мои отпечатки, если честно на самом деле я Роман Шевцов";
    ss dima = "Тут отпечатки Дмитрия Рыблова.. Кто бы мог подумать, он коварный поедатель";
    cout << "1 - Сказать правду\n2 - Соврать\n";
    cin >> choise;
    switch (choise) {
    case 1:
        endings["true_end"] = 100;
        text_out(nu_text);
        br;
    case 2:
        endings["other_end"] = 101;
        text_out(dima);
        br;
    }
    end_game();
}
/////////////////////////////////////////////////
void default_choise() {
    clear_console();
    change_color("31", "1");
    ss wrong_text = "Ой, похоже мы здесь уже были, память уже совсем отшибло из-за фенибута";
    text_out(wrong_text);
    reset_color();
    sleep_l(100);
    clear_console();
    begin_choise();
}

void end_game() {
    int mx = -1;
    ss endya;
    for (auto endi : endings) {
        if (endi.second > mx) {
            mx = endi.second;
            endya = endi.first;
        }
    }

    if (mx == 100) {
        roma();
    }
    else if (mx == 101) {
        dima();
    }
    else {
        if (endya == "dog_end") {
            doga();
        }
        else if (endya == "true_end") {
            roma();
        }
        else if (endya == "other_end") {
            dima();
        }
    }
    exit(0);
}
/////КОНЦОВКИ///
void roma() {
    ss roma_text = "Я должен признаться...\nНо все это время я был Романом Шевцовым и на самом деле это я съел сосисоны\nК сожалению я больше не мог этого скрывать, но думаю вы уже сами догадались";
    ss ans_roma = "-Да, я уже давно догадался, моя собака тебя узнала, потому что ты даже не удосужился помыться и ты очень странно себя вел";
    change_color("31", "1");
    text_out(roma_text);
    reset_color();
    sleep_l(300);
    text_out(ans_roma);
    exit(0);
}
void dima() {
    ss dima_text = "Очень жаль, но все улики ведут к тому, что это Дмитрий Рыблов\nЭтот коварный гений съел сосиски";
    ss ans_dima = "-Святые угодники, я так и знал, но до конца не мог поверить, спасибо детектив";
    change_color("35", "1");
    text_out(dima_text);
    reset_color();
    sleep_l(300);
    text_out(ans_dima);
    exit(0);
}
void doga() {
    ss doga_text = "Неприятно это говорить, но кажется эта милая собачка Фифа съела сосиски...\nНе спрашивайте как она их сварила, это загадка";
    ss doga_ans = "эээмэмэмэ ладно детектив, я вам верю, в следующий раз буду лучше за ней следить";
    change_color("34", "1");
    text_out(doga_text);
    reset_color();
    sleep_l(300);
    text_out(doga_ans);
    exit(0);
}
//////////
void end_game_concid() {
    ss concid_text = "-Очень жаль, что вы испугались этого дела, видимо я в вас ошибся";
    ss anser_text = "-Да, пук мук извините...";
    change_color("31", "1");
    text_out(concid_text);
    reset_color();
    sleep_l(300);
    change_color("34", "");
    text_out(anser_text);
    reset_color();
    exit(0);
}

void clear_console() {
    system("cls");
}

void waiting() {
    clear_console();
    for (int i = 0; i < 3; i++) {
        text_out("...");
        sleep_l(300);
    }
    clear_console();
}
///////////////////////////////////////////////
void sleep_l(unsigned int milliseconds_) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds_));
}
//black        30         
//red          31        
//green        32        
//yellow       33        
//blue         34        
//magenta      35        
//cyan         36        
//white        37        
void change_color(ss color, ss j) {
    if (j == "1" || j == "4")
        cout << "\033[" + j + ";" + color + "m";
    else
        cout << "\033[" + color + "m";
}
void reset_color() {
    cout << "\033[0m";
}
/// Функция для красивого вывода текста ///
void text_out(ss text) {
    int sleep_ = 10;
    for (auto symbol : text) {
        cerr << symbol << flush;
        sleep_l(sleep_);
    }
    cout << endl;
}
//////////////////////////////////////////
int main()
{
    system("cls");
    //INIT//
    endings["true_end"] = 0;
    endings["other_end"] = 0;
    endings["dog_end"] = 0;
    ///
    used_loc["kitchen"] = false;
    used_loc["living_room"] = false;
    used_loc["bathroom"] = false;
    used_loc["outdoor"] = false;
    setlocale(LC_ALL, "Russian");
    ///////
    begin_game();
}
