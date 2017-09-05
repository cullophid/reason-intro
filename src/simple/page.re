let component = ReasonReact.statelessComponent "Page";
let text = ReasonReact.stringToElement;
let make _ => {
  {
    ...component,
    render: fun _ => {
      <h1> (text "Hello world") </h1>
    }
  }
};
