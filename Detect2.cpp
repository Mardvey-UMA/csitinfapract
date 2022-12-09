#include <iostream>
#include "windows.h"
#include <string>
#include <map>
#define br break;
using namespace std;
typedef string ss;

int choise;
int gl_sl = 500;
int lim = 2;
bool clean_flag = false;
map <string, int> endings;
map <string, bool> used_loc;

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

//Системные штуки
void end_game();
void text_out(string text);
void clear_console();
void change_color(ss color);
void waiting();
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
        Sleep(gl_sl);
        endings["other_end"]++;
        cleaning_choise();
        br;
    case 2:
        text_out(wrong_text);
        end_game();
        br;
    }
}

void cleaning_choise() {
    clear_console();
    ss wrong_text = "*Фу, ну я и грязный конечно, ну да не страшно. Панку нужны только три вещи...\nИ не стирать их*";
    text_out("Помыться?");
    cout << "1 - Да\n2 - Нет\n";
    cin >> choise;
    switch (choise) {
    case 1:
        clean_flag = true;
        endings["dog_end"]++;
        br;
    case 2:
        text_out(wrong_text);
        Sleep(gl_sl);
        br;
    }
    waiting();
    ss hello_text = "-Здравствуйте, детектив Шоман Ремцов.Спасибо, что согласились помочь в расследовании этого дела. \nК сожалению многие отказались от него, возможно из-за его абсурдности, но оно очень важно для меня. \nСегодня 12 ноября 2022 года, мы находимся в моей квартире, здесь небольшой беспорядок, так как 141 группа факультета КниИТ праздновала написание коллоквиума, если вам интересно то у меня 9 баллов.\nИ произошла одна неприятная вещь… Во время празднования кто-то украл сосиски из холодильника сварил их и съел. \nДом в вашем распоряжении можете все обыскать. Возможно вы обнаружите улики..";
    text_out(hello_text);
    begin_choise();
}



void end_game() {
    clear_console();
    cout << "Конец";
}

void clear_console() {
    system("cls");
}

void waiting() {
    clear_console();
    for (int i = 0; i < 3; i++) {
        text_out("...");
        Sleep(30);
    }
    clear_console();
}

void begin_choise() {
    cout << "1 - Выйти на улицу\n2 - Зайти на кухню\n3 - Осмотреть зал\n4 - Осмотреть ванную\n5 - Сдаться\n";
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
        end_game();
        br;
    }
}

void bathroom_choise() {
    ss rtext = "*заходят в ванную*\nТут только грязный кошачий лоток, стаканчик с бритвами и зубной щеткой.\nНедовольная кошка пьющая воду.Пожалуй больше не будем сюда заходить.Здесь нет ничего интересного.";
    if (used_loc["bathroom"])
        default_choise();
    else{
        used_loc["bathroom"] = true;
        text_out(rtext);
    }
    
}

void outdoor_choise() {
    if (used_loc["outdoor"])
        default_choise();
    else {
        used_loc["outdoor"] = true;
        ss begin_text = "-Для начала давайте осмотрим улицу.";
        ss description_text = "*выходят на улицу* \nПеред вами открывается пустынный ноябрьский, холодный пейзаж Волжского района.\nНа улице лежит мусорный пакет с бутылками, бычками сигарет.\nВы с энтузиазмом роетесь в пакете и обнаруживаете там пленки от сосисок.";
        ss ans1 = "-Да, это она, и что нам это дает, ведь я собирал мусор ночью и мало что помню…";
        ss ans1_dec = "-Возможно вам кто-то помогал, и этот кто-то не хотел, чтобы вы вспомнили о сосисках.";
        ss ans2 = "-Какой-то вы молчун…";
        change_color("blue");
        text_out(description_text);
        cout << "1 - Спросить является ли эти пленки пленками от тех сосисок\n2 - Многозначительно промолчать\n";
        cin >> choise;
        switch (choise) {
        case 1:
            text_out(ans1);
            text_out(ans1_dec);
            endings["true_end"]--;
            Sleep(gl_sl);
            br;
        case 2:
            text_out(ans2);
            endings["true_end"]++;
            Sleep(gl_sl);
            br;
        }
        clear_console();
        change_color("aboba");
        begin_choise();
    }
}

void kitchen_choise() {
    if (used_loc["kitchen"])
        default_choise();
    else {
        used_loc["kitchen"] = true;
        ss hello_text = "-Для начала давайте осмотрим кухню.";
        ss description_text = "*заходят на кухню*\nКоробки от пиццы, грязная посуда, куча пепельниц сделанных из всего, что было под рукой.\nУжасная вонь.Видите единственную тарелку на столе, на ней тонкая пленка бульона.";
        ss ans1 = "– Что-то мне не нравится ваше поведение, зачем вы нюхаете тарелку?";
        ss ans2 = "ЧТО ВЫ ТВОРИТЕ????? ВЫ В СВОЕМ УМЕ, А ЕСЛИ Я ПОРЕЖУСЬ??? \nИ вообще эта тарелка стоит денег…";
        text_out(description_text);
        cout << "1 - Понюхать тарелку\n2 - Взять тарелку и бросить об стену\n3 - Помыть тарелку\n";
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
        }
    }
}

void living_room_choise() {
    if (used_loc["living_room"])
        default_choise();
    else{
        used_loc["living_room"] = true;
        ss description_text = "*заходят в зал*\nПо дивану прыгает маленькая собачка Фифа.Она радостно бежит к вам и обнюхивает вас.";
        ss hello_text = "-Для начала давайте осмотрим зал.";
        ss var_txt = "Хмм моя собака очень рада вас видеть и виляет хвостом, как будто она вас когда-то видела";
        ss next_text = "На грязном столе, покрытым странными сладкими пятнами красуется алюминиевая кастрюлька.";
        text_out(hello_text);
        text_out(description_text);
        if (clean_flag) {
            endings["true_end"]++;
            text_out(var_txt);
        }
        text_out(next_text);
    }
    ss dog_end_text = "Отлично, дело раскрыто, в преть советую вам получше следить за собакой, за свою улетность денег не беру. \nСпасибо, но можете одолжить велосипед на выходные, я хочу поработать кхм кхм…";
    ss ans1 = "-Почему вы так в этом уверены? \nВаша собака очень обрадовалась вам, и я честно очень сомневаюсь в том, что она могла сама сварить сосиски.";
    ss kastr_descr = "*Алюминиевая, ручка вяло болтается на слабом шурупчике. \nУниверсальная кастрюля, в ней можно и пельмешек сварить и черпать воду, если вдруг затопит...*";
    ss quest1 = "-Да, я рад, что вам понравилось, но все таки как это поможет делу?";
    cout << "1 - Обвинить собаку\n2 - Осмотреть кастрюлю\n";
    cin >> choise;
    switch (choise) {
    case 1:
        if (endings["dog_end"] >= 1 && endings["true_end"] < lim) {
            text_out(dog_end_text);
            system(0);
        }
        else {
            text_out(ans1);
            endings["true_end"]++;
        }
        br;
    case 2:
        text_out(kastr_descr);
        text_out(quest1);
        br;
    }
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
    Sleep(gl_sl);
    kitchen_choise();
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
    Sleep(gl_sl);
    kitchen_choise();
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
        br;
    }
}

void otpechat_choise() {
    ss nu_text = "Тут мои отпечатки, если честно на самом деле я Роман Шевцов";
    ss dima = "Тут отпечатки Дмитрия Рыблова.. Кто бы мог подумать, он коварный поедатель";
    cout << "1 - Сказать правду\n2 - Соврать";
    cin >> choise;
    switch (choise) {
    case 1:
        text_out(nu_text);
        br;
    case 2:
        text_out(dima);
        br;
    }
}

void default_choise() {
    clear_console();
    ss wrong_text = "Ой, похоже мы здесь уже были, память уже совсем отшибло из-за пиродола";
    change_color("red");
    text_out(wrong_text);
    Sleep(100);
    change_color("aboba");
    clear_console();
    begin_choise();
}
/// Функция для красивого вывода текста ///
void text_out(string text) {
    int sleep_ = 0;
    for (auto symbol : text) {
        cout << symbol;
        Sleep(sleep_);
    }
    cout << endl;
}
//////////////////////////////////////////
void change_color(ss color) {
    if (color == "green") {
        system("color 2");
    }
    else if (color == "blue") {
        system("color 3");
    }
    else if (color == "red") {
        system("color 4");
    }
    else if (color == "yell") {
        system("color 6");
    }
    else if (color == "gray") {
        system("color 8");
    }
    else if (color == "black") {
        system("color 0");
    }
    else
        system("color 7");
}
int main()
{
    change_color("aboba");
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
