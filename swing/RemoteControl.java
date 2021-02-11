import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import java.awt.event.*;
import java.awt.BorderLayout;
import java.awt.GridLayout;

public class RemoteControl extends JFrame {
    private static final long serialVersionUID = 1L;

    AbstractAction play;
    AbstractAction search;
    AbstractAction exit;

    JTextArea textArea = new JTextArea();
    JPanel buttonPanel = new JPanel();
    JScrollPane scrollPane;
    JMenuBar menuBar;
    JToolBar toolBar;

    //Variables for the client
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    static Client client;

    public static void main(String argv[]) {
        new RemoteControl();

        //Java client
        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        if (argv.length >= 1)
            host = argv[0];
        if (argv.length >= 2)
            port = Integer.parseInt(argv[1]);

        //Client client = null;

        try {
            client = new Client(host, port);
        } catch (Exception e) {
            System.err.println("Client: Couldn't connect to " + host + ":" + port);
            System.exit(1);
        }

        System.out.println("Client connected to " + host + ":" + port);

    }

    public RemoteControl() {
        setLayout(new BorderLayout());

        play = new PlayAction();
        search = new SearchAction();
        exit = new ExitAction();

        //Create the buttons and the text area and put them in a panel
        buttonPanel.setLayout(new GridLayout(1, 3));
        buttonPanel.add(new JButton(play));
        buttonPanel.add(new JButton(search));
        buttonPanel.add(new JButton(exit));

        textArea.setEditable(false);
        textArea.setText(
                "You can search or play a media by clicking the corresponding button and typing the media name.");
        textArea.setLineWrap(true);

        add(buttonPanel, BorderLayout.SOUTH);
        add(scrollPane = new JScrollPane(textArea), BorderLayout.CENTER);

        //Adding the menu
        JMenu menu = new JMenu("Menu");
        menuBar = new JMenuBar();
        menuBar.add(menu);
        menu.add(play);
        menu.add(search);
        menu.add(exit);

        //Adding the toolbar
        toolBar = new JToolBar();
        toolBar.add(new PlayAction());
        toolBar.add(new SearchAction());
        toolBar.add(new ExitAction());
        add(toolBar, BorderLayout.NORTH);

        //Set settings and show the window
        setJMenuBar(menuBar);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setSize(600, 600);
        setVisible(true);

    }

    class PlayAction extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public PlayAction() {
            this.putValue(AbstractAction.NAME, "Play");
        }

        public void actionPerformed(ActionEvent e) {
            String text = textArea.getText();
            String name = JOptionPane.showInputDialog(null, "Media or group name to play", "Media/Group input",
                    JOptionPane.QUESTION_MESSAGE);

            try {
                textArea.setText(text + "play " + name + "\n" + client.send("play " + name) + "\n");
            } catch (Exception err) {
                System.err.println("Client: IO error");
            }
        }
    }

    class SearchAction extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public SearchAction() {
            this.putValue(AbstractAction.NAME, "Search");
        }

        public void actionPerformed(ActionEvent e) {
            String text = textArea.getText();
            String name = JOptionPane.showInputDialog(null, "Media or group name to search", "Media/Group input",
                    JOptionPane.QUESTION_MESSAGE);

            try {
                textArea.setText(text + "search " + name + "\n" + client.send("search " + name) + "\n");
            } catch (Exception err) {
                System.err.println("Client: IO error");
            }
        }
    }

    class ExitAction extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public ExitAction() {
            this.putValue(AbstractAction.NAME, "Exit");
        }

        public void actionPerformed(ActionEvent e) {
            System.exit(1);
        }
    }

}